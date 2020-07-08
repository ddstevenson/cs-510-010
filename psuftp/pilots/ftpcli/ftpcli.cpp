#include <Poco/Net/FTPClientSession.h>
#include <Poco/Net/NetException.h>

#include <boost/scope_exit.hpp>

#include <fmt/printf.h>

namespace Net = Poco::Net;

int main(int argc, const char *argv[]) {
    try {
        auto ftpSession = Net::FTPClientSession{};
        ftpSession.open(
            "localhost"
          , Net::FTPClientSession::FTP_PORT
          , "::1"
          , "user@server.com"
        );
        BOOST_SCOPE_EXIT_ALL(&) {
            ftpSession.close();
        };
        auto resp = std::string{};
        ftpSession.sendCommand("STAT", resp);
        fmt::print("{}\n", resp);
        {
            auto &dirStream = ftpSession.beginList();
            BOOST_SCOPE_EXIT_ALL(&) {
                ftpSession.endList();
            };
            auto buf = std::string(4096, '\0');
            while (dirStream.good()) {
                dirStream.getline(&buf[0], buf.size());
                fmt::print("{}\n", buf);
            }
        }
    } catch (Net::FTPException &x) {
        fmt::print("{}\n", x.what());
    }
}
