cmake_minimum_required(VERSION 3.16)

add_library(fmt
    src/format.cc
    src/os.cc
)
target_include_directories(fmt PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
