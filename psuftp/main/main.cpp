#include <string>

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

#include <fmt/color.h>
#include <fmt/printf.h>

#include "client.h"

namespace fs = boost::filesystem;
namespace po = boost::program_options;

void PrintUsage(const std::string &prgName) {
    fmt::print("Usage: {} host [port]\n", prgName);
}

int main(int argc, char *argv[]) {
    auto positional     = po::positional_options_description{};
    auto cmdLineOptions = po::options_description{};
    auto vm             = po::variables_map{};

    auto host = std::string{};
    auto port = std::string{};

    // clang-format off
    cmdLineOptions.add_options()
        ("host", po::value<decltype(host)>(&host)->required(), "")
        ("port", po::value<decltype(port)>(&port)->default_value("FTP"), "");
    // clang-format on
    positional.add("host", 1);
    positional.add("port", 1);

    try {
        po::store(po::command_line_parser(argc, argv)
                      .positional(positional)
                      .options(cmdLineOptions)
                      .run(),
                  vm);
        po::notify(vm);
    } catch (po::error &x) {
        fmt::print(stderr,
                   fmt::fg(fmt::color::coral) | fmt::emphasis::bold,
                   "Command line error: {}\n",
                   x.what());
        PrintUsage(fs::path(argv[0]).stem().string());
        return 1;
    }

    try {
        Client test;
        return 0;
    } catch (std::exception &x) {
        fmt::print(stderr, "{}\n", x.what());
        return 1;
    }
}
