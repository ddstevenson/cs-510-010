cmake_minimum_required(VERSION 3.16)

add_executable(ftptests
    ftptests.cpp
    connect.cpp
    ftpserver.cpp
)

set_source_files_properties(ftpserver.cpp PROPERTIES COMPILE_OPTIONS -Wno-write-strings)

target_link_libraries(ftptests
    uftpd
    fmt
    pthread
)
