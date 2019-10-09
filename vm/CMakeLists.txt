cmake_minimum_required(VERSION 3.14)
project(VM C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS -v)

AUX_SOURCE_DIRECTORY(../libft/src LIBA)

add_executable(
        VM
        ${LIBA}
        src/arg_read.c
        src/carriage.c
        src/check_args.c
        src/check_players.c
        src/fight.c
        src/main.c
        src/mem_clean.c
        src/op.c
        inc/corewar_vm.h
        src/player.c
        src/player_id.c
        src/players.c
        src/printer.c
        src/op_live.c
        src/op_ld.c
        src/op_and.c
        src/op_xor.c
        src/op_or.c
        src/op_st.c
        src/op_add.c
        src/op_sub.c
        src/op_zjmp.c
        src/op_ldi.c
        src/op_sti.c
        src/op_fork.c
        src/op_lld.c
        src/op_lldi.c
        src/op_lfork.c
        src/op_aff.c
        src/get_val.c
        src/check_live_carriage.c
        src/errors.c)

link_libraries(../libft/libft.a)