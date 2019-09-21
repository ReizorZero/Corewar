cmake_minimum_required(VERSION 3.14)
project(VM C)

set(CMAKE_C_STANDARD 99)

AUX_SOURCE_DIRECTORY(libft LIBA)

add_executable(vm
        main.c)

link_libraries(libft/libft.a)