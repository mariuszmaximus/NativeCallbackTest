cmake_minimum_required(VERSION 3.10.2)

project("nativecallbacktest")

add_library(library1 SHARED library1.c)
add_library(library2 SHARED library2.c)

# Biblioteka 2 zależy od biblioteki 1
target_link_libraries(library2 library1 log)

# Linkuj bibliotekę log do każdej z bibliotek
target_link_libraries(library1 log)
