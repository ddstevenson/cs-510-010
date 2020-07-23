cmake_minimum_required(VERSION 3.16)

set(FTPD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(libite)
add_subdirectory(libuev)
add_subdirectory(uftpd)
