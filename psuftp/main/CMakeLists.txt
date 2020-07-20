cmake_minimum_required(VERSION 3.16)

find_package(fmt REQUIRED)

add_executable(psuftp
    client.cpp
    main.cpp
    servInfo.cpp
    user.cpp
)

set_property(TARGET psuftp PROPERTY CXX_STANDARD 20)

target_link_libraries(psuftp
    Net
    fmt::fmt
    program_options
)

target_include_directories(psuftp PRIVATE ${PROJECT_SOURCE_DIR})
target_compile_options(psuftp PRIVATE
    -fdiagnostics-color=always
)
