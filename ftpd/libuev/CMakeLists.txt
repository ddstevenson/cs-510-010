cmake_minimum_required(VERSION 3.16)

add_library(uev
    uev.c
    io.c
    signal.c
    timer.c
    event.c
    cron.c
)
target_include_directories(uev PUBLIC
    ${FTPD_INCLUDE_DIR}/uev
)
