cmake_minimum_required(VERSION 3.14)
project(VM C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS -v)

AUX_SOURCE_DIRECTORY(../libft/src LIBA)

add_executable(
        VM
        ${LIBA}
        src/main.c
        inc/corewar_vm.h
        src/carriage.c
        src/player.c
        src/mem_clean.c
        src/op_live.c
        src/op.c
        src/arg_read.c
        src/fight.c
        src/op_ld.c
        src/op_and.c
        src/op_xor.c
        src/op_or.c)

link_libraries(../libft/libft.a)