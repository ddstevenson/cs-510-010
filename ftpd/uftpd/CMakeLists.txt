cmake_minimum_required(VERSION 3.16)

add_library(uftpd
    log.c
    ftpcmd.c
    common.c
)
target_include_directories(uftpd PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_include_directories(uftpd PRIVATE
    ${FTPD_INCLUDE_DIR}
)
target_link_libraries(uftpd PUBLIC
    uev ite
)
target_compile_options(uftpd PRIVATE
    -Wno-write-strings
)
target_compile_definitions(uftpd PRIVATE
    _XOPEN_SOURCE=600
)
