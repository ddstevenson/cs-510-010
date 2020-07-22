cmake_minimum_required(VERSION 3.16)

add_executable(ftptests
    ftptests.cpp
    connect.cpp
)

target_link_libraries(ftptests
    test_framework
)
