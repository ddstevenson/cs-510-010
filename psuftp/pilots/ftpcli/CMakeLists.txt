cmake_minimum_required(VERSION 3.16)

project(ftpcli)

find_package(fmt REQUIRED)
find_package(Poco CONFIG REQUIRED Net)
find_package(Boost REQUIRED COMPONENTS system)

add_executable(ftpcli
    ftpcli.cpp
)

set_property(TARGET ftpcli PROPERTY CXX_STANDARD 20)

target_link_libraries(ftpcli
    Poco::Net
    fmt::fmt
)

target_include_directories(ftpcli PRIVATE ${PROJECT_SOURCE_DIR} ${Boost_INCLUDE_DIRS})
target_compile_options(ftpcli PRIVATE
    -fdiagnostics-color=always
)
