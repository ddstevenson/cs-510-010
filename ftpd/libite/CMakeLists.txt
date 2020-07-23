cmake_minimum_required(VERSION 3.16)

add_library(ite
    pidfile.c
    strlcat.c
    strlcpy.c
    strtonum.c
)
target_include_directories(ite PUBLIC
    ${FTPD_INCLUDE_DIR}
)
target_compile_definitions(ite PRIVATE
    __STDC_WANT_LIB_EXT2__
)
target_compile_definitions(ite PUBLIC
    _DEFAULT_SOURCE # otherwise strlite.h won't compile
)
