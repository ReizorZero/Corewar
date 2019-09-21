cmake_minimum_required(VERSION 3.14)
project(VM C)

set(CMAKE_C_STANDARD 99)

AUX_SOURCE_DIRECTORY(../libft/src LIBA)

add_executable(
        VM
        ${LIBA}
        src/main.c
        inc/corewar_vm.h
        src/carriage.c)

link_libraries(../libft/libft.a)