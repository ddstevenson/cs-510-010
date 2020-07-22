cmake_minimum_required(VERSION 3.16)

project(PSU-FTP-Client)

add_compile_options(-fdiagnostics-color=always)

add_subdirectory(psuftp)
add_subdirectory(boost)
add_subdirectory(poco)
add_subdirectory(fmt)
