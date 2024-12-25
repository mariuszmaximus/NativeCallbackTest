cmake_minimum_required(VERSION 3.10.2)

project("nativecallbacktest")

add_library(draminski SHARED draminski.c)
add_library(leltek SHARED leltek.c)

target_link_libraries(draminski log)

target_link_libraries(leltek log)

