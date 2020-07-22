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

add_library(filesystem
    libs/filesystem/src/path.cpp
)

add_library(test_framework
    libs/test/src/compiler_log_formatter.cpp
    libs/test/src/junit_log_formatter.cpp
    libs/test/src/test_main.cpp
    libs/test/src/unit_test_parameters.cpp
    libs/test/src/cpp_main.cpp
    libs/test/src/plain_report_formatter.cpp
    libs/test/src/test_tools.cpp
    libs/test/src/xml_log_formatter.cpp
    libs/test/src/debug.cpp
    libs/test/src/progress_monitor.cpp
    libs/test/src/test_tree.cpp
    libs/test/src/xml_report_formatter.cpp
    libs/test/src/decorator.cpp
    libs/test/src/results_collector.cpp
    libs/test/src/unit_test_log.cpp
    libs/test/src/execution_monitor.cpp
    libs/test/src/results_reporter.cpp
    libs/test/src/unit_test_main.cpp
    libs/test/src/framework.cpp
    libs/test/src/test_framework_init_observer.cpp
    libs/test/src/unit_test_monitor.cpp
)

target_compile_definitions(program_options PUBLIC
    BOOST_BIND_GLOBAL_PLACEHOLDERS
    BOOST_ALL_NO_LIB
)
target_include_directories(program_options PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(filesystem PUBLIC
    BOOST_BIND_GLOBAL_PLACEHOLDERS
    BOOST_ALL_NO_LIB
)
target_include_directories(filesystem PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(test_framework PUBLIC
    BOOST_BIND_GLOBAL_PLACEHOLDERS
    BOOST_ALL_NO_LIB
)
target_include_directories(test_framework PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
