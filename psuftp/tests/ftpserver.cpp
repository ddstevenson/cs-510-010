#include <stdexcept>

#include "ftpserver.h"

extern "C" {
#include <uev.h>
#include <uftpd.h>
}

char *         prognm      = PACKAGE_NAME;
char *         home        = NULL;
int            inetd       = 0;
int            background  = 0;
int            do_syslog   = 0;
int            do_ftp      = 3739;
int            do_insecure = 1;
struct passwd *pw          = NULL;

namespace
{
    uev_t ftp_watcher;
    uev_t sigchld_watcher;
    uev_t sigterm_watcher;
    uev_t sigint_watcher;
    uev_t sighup_watcher;
    uev_t sigquit_watcher;

    int init(uev_ctx_t *ctx) {
        if (!home) {
            pw = getpwnam(FTP_DEFAULT_USER);
            if (!pw) {
                WARN(errno,
                     "Cannot find user %s, falling back to %s as FTP root.",
                     FTP_DEFAULT_USER,
                     FTP_DEFAULT_HOME);
                home = strdup(FTP_DEFAULT_HOME);
            } else {
                home = strdup(pw->pw_dir);
            }
        }

        if (!home || access(home, F_OK)) {
            ERR(errno, "Cannot access FTP root %s", home ? home : "NIL");
            return 1;
        }

        return uev_init(ctx);
    }

    void ftp_cb(uev_t *w, void *arg, int events) {
        int client;

        if (UEV_ERROR == events || UEV_HUP == events) {
            uev_io_stop(w);
            close(w->fd);
            return;
        }

        client = accept(w->fd, NULL, NULL);
        if (client < 0) {
            WARN(errno, "Failed accepting FTP client connection");
            return;
        }

        ftp_session(static_cast<uev_ctx_t *>(arg), client);
    }

    int start_service(uev_ctx_t *ctx, uev_t *w, uev_cb_t *cb, int port, int type, char *desc) {
        int sd;

        if (!port)
            /* Disabled */
            return 1;

        sd = open_socket(port, type, desc);
        if (sd < 0) {
            if (EACCES == errno)
                WARN(0,
                     "Not allowed to start %s service.%s",
                     desc,
                     port < 1024 ? "  Privileged port." : "");
            return 1;
        }

        INFO("Starting %s server on port %d ...", desc, port);
        uev_io_init(ctx, w, cb, ctx, sd, UEV_READ);

        return 0;
    }

    int serve_files(uev_ctx_t *ctx) {
        int ftp;

        DBG("Starting services ...");
        ftp = start_service(ctx, &ftp_watcher, ftp_cb, do_ftp, SOCK_STREAM, "FTP");

        /* Check if failed to start any service ... */
        if (ftp)
            return 1;

        /* We're now up and running, save pid file. */
        pidfile(NULL);

        INFO("Serving files from %s ...", home);

        return uev_run(ctx, 0);
    }

    void StopServer(uev_t *w, void *arg, int events) {
        uev_exit(reinterpret_cast<uev_ctx_t *>(arg));
    }
} // namespace

FTPServerFixture::FTPServerFixture() {
    loglevel = LOG_DEBUG;
    DBG("Initializing ...");
    if (init(&ctx)) {
        throw std::runtime_error("Failed initializing, exiting.");
    }
    uev_event_init(&ctx, &stopEvent, StopServer, &ctx);

    DBG("Serving files as PID %d ...", getpid());
    ftpThread = std::thread([this]() { serve_files(&ctx); });
}

FTPServerFixture::~FTPServerFixture() {
    DBG("Waiting for the FTP Server to shutdown...");
    uev_event_post(&stopEvent);
    ftpThread.join();
}
