# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshvets <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 14:14:54 by mshvets           #+#    #+#              #
#    Updated: 2019/09/04 14:15:19 by mshvets          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of the executable file

NAME_VM	        := corewar
NAME_ASM        := asm

# project directories

VM_SRC_DIR      = ./vm/src/
VM_OBJ_DIR      = ./vm/obj/
ASM_SRC_DIR     = ./compiler/src/
ASM_OBJ_DIR     = ./compiler/obj/
INC_DIR         = ./inc/
LIB_DIR         = ./

# project source files

VM_SRC          := $(VM_SRC_DIR)arg_read.c
VM_SRC          += $(VM_SRC_DIR)carriage.c
VM_SRC          += $(VM_SRC_DIR)check_args.c
VM_SRC          += $(VM_SRC_DIR)check_players.c
VM_SRC          += $(VM_SRC_DIR)fight.c
VM_SRC          += $(VM_SRC_DIR)main.c
VM_SRC          += $(VM_SRC_DIR)mem_clean.c
VM_SRC          += $(VM_SRC_DIR)op_add.c
VM_SRC          += $(VM_SRC_DIR)op_aff.c
VM_SRC          += $(VM_SRC_DIR)op_and.c
VM_SRC          += $(VM_SRC_DIR)op_fork.c
VM_SRC          += $(VM_SRC_DIR)op_ld.c
VM_SRC          += $(VM_SRC_DIR)op_ldi.c
VM_SRC          += $(VM_SRC_DIR)op_lfork.c
VM_SRC          += $(VM_SRC_DIR)op_live.c
VM_SRC          += $(VM_SRC_DIR)op_lld.c
VM_SRC          += $(VM_SRC_DIR)op_lldi.c
VM_SRC          += $(VM_SRC_DIR)op_or.c
VM_SRC          += $(VM_SRC_DIR)op_st.c
VM_SRC          += $(VM_SRC_DIR)op_sti.c
VM_SRC          += $(VM_SRC_DIR)op_sub.c
VM_SRC          += $(VM_SRC_DIR)op_xor.c
VM_SRC          += $(VM_SRC_DIR)op_zjmp.c
VM_SRC          += $(VM_SRC_DIR)op.c
VM_SRC          += $(VM_SRC_DIR)player_id.c
VM_SRC          += $(VM_SRC_DIR)player.c
VM_SRC          += $(VM_SRC_DIR)players.c
VM_SRC          += $(VM_SRC_DIR)printer.c
VM_SRC          += $(VM_SRC_DIR)get_val.c
VM_SRC          += $(VM_SRC_DIR)check_live_carriage.c
VM_SRC          += $(VM_SRC_DIR)errors.c
VM_SRC          += $(VM_SRC_DIR)vis_init.c
VM_SRC          += $(VM_SRC_DIR)visualiser.c

ASM_SRC         := $(ASM_SRC_DIR)add_elements.c
ASM_SRC         += $(ASM_SRC_DIR)args_types_tools.c
ASM_SRC         += $(ASM_SRC_DIR)check_args_types.c
ASM_SRC         += $(ASM_SRC_DIR)check_asm_input.c
ASM_SRC         += $(ASM_SRC_DIR)check_command_line.c
ASM_SRC         += $(ASM_SRC_DIR)check_comment.c
ASM_SRC         += $(ASM_SRC_DIR)check_if_words_correct.c
ASM_SRC         += $(ASM_SRC_DIR)check_name.c
ASM_SRC         += $(ASM_SRC_DIR)cmnd_line_tools.c
ASM_SRC         += $(ASM_SRC_DIR)cmnd_line_tools_2.c
ASM_SRC         += $(ASM_SRC_DIR)comment_tools.c
ASM_SRC         += $(ASM_SRC_DIR)functions.c
ASM_SRC         += $(ASM_SRC_DIR)label_tools.c
ASM_SRC         += $(ASM_SRC_DIR)main.c
ASM_SRC         += $(ASM_SRC_DIR)name_tools.c
ASM_SRC         += $(ASM_SRC_DIR)new_elements.c
ASM_SRC         += $(ASM_SRC_DIR)parse_lines.c
ASM_SRC         += $(ASM_SRC_DIR)read_from_dot_s.c
ASM_SRC         += $(ASM_SRC_DIR)words_tools.c
ASM_SRC         += $(ASM_SRC_DIR)words_tools_2.c
ASM_SRC         += $(ASM_SRC_DIR)write_cmnd_line_words.c
ASM_SRC         += $(ASM_SRC_DIR)write_to_dot_cor.c

# project object files

VM_OBJ		        = $(VM_SRC:$(VM_SRC_DIR)%.c=$(VM_OBJ_DIR)%.o)
ASM_OBJ		        = $(ASM_SRC:$(ASM_SRC_DIR)%.c=$(ASM_OBJ_DIR)%.o)

# libraries

LIB             := $(LIBFT_DIR)libft.a
LIBFT_DIR       := $(LIB_DIR)libft/
LIBFT_INC       := $(LIBFT_DIR)
LIBFT_FLAGS     := -lft -L $(LIBFT_DIR)

# compilation flags

CC_FLAGS        := -Wall -Wextra -Werror

# linking flags

LINK_FLAGS      := $(LIBFT_FLAGS)

# header flags

HEAD            := $(INC_DIR)corewar_vm.h
HEADER_FLAGS    := -I $(INC_DIR) -I $(LIBFT_INC)

# compiler

CC              := gcc

# rules

all: $(LIB) $(NAME_VM) $(NAME_ASM)

$(NAME_VM): $(VM_OBJ)
	$(CC) $(VM_OBJ) $(LINK_FLAGS) -o $(NAME_VM) -lncurses

$(NAME_ASM): $(ASM_OBJ)
	$(CC) $(ASM_OBJ) $(LINK_FLAGS) -o $(NAME_ASM)

$(VM_OBJ_DIR)%.o: $(VM_SRC_DIR)%.c
	$(CC) $(CC_FLAGS) -c $< -o $@ $(HEADER_FLAGS)

$(ASM_OBJ_DIR)%.o: $(ASM_SRC_DIR)%.c
	$(CC) $(CC_FLAGS) -c $< -o $@ $(HEADER_FLAGS)

$(LIB):
	make -C $(LIBFT_DIR)

$(VM_OBJ): | $(VM_OBJ_DIR)

$(ASM_OBJ): | $(ASM_OBJ_DIR)

$(VM_OBJ_DIR):
	mkdir -p $(VM_OBJ_DIR)

$(ASM_OBJ_DIR):
	mkdir -p $(ASM_OBJ_DIR)

clean:
	rm -f $(VM_OBJ)
	rm -f $(ASM_OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME_VM)
	rm -f $(NAME_ASM)
	make fclean -C $(LIBFT_DIR)

re: fclean all

reclean: fclean all
#	rm -f $(VM_OBJ)
#	rm -f $(ASM_OBJ)
