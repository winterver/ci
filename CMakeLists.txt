cmake_minimum_required(VERSION 3.5)
project(ci)

add_executable(ci src/ci.yy.c src/ci.tab.c)

if(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(ci PRIVATE
        /Wall /wd4255 /wd4242 /wd4244
        /wd4267 /wd4710 /wd4711 /wd4820
        /wd5045 /wd4065)
else()
    target_compile_options(ci PRIVATE
        -Wall -Wextra -Wno-strict-aliasing
        -Wno-pointer-sign)
endif()
