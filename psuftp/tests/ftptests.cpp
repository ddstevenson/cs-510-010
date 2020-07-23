#define BOOST_TEST_MODULE "Unit Tests for FTP client"
#include <boost/test/included/unit_test.hpp>

#include "ftpserver.h"

// an FTP serever will be functioning for the duration of tests
BOOST_GLOBAL_FIXTURE(FTPServerFixture);
