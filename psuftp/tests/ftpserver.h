#pragma once

#include <thread>

extern "C" {
#include <uev.h>
}

// Creates and destructs an FTP server for the test suites
class FTPServerFixture
{
public:
    static constexpr auto TestPort = 3739;

    FTPServerFixture();
    ~FTPServerFixture();

private:
    uev_ctx_t   ctx = {};
    uev_t       stopEvent;
    std::thread ftpThread;
};
