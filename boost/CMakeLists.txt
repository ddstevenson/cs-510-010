cmake_minimum_required(VERSION 3.16)

add_library(program_options
    libs/program_options/src/cmdline.cpp
    libs/program_options/src/convert.cpp
    libs/program_options/src/options_description.cpp
    libs/program_options/src/positional_options.cpp
    libs/program_options/src/utf8_codecvt_facet.cpp
    libs/program_options/src/value_semantic.cpp
    libs/program_options/src/variables_map.cpp
)
target_compile_definitions(program_options PUBLIC
    BOOST_BIND_GLOBAL_PLACEHOLDERS
)
target_include_directories(program_options PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
