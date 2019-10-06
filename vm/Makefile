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

NAME		:= corewar

# project directories

SRC_DIR     = ./src/
OBJ_DIR     = ./obj/
INC_DIR     = ./inc/
LIB_DIR     = ../

# project source files
SRC             := $(SRC_DIR)arg_read.c
SRC             += $(SRC_DIR)carriage.c
SRC             += $(SRC_DIR)check_args.c
SRC             += $(SRC_DIR)check_players.c
SRC             += $(SRC_DIR)fight.c
SRC             += $(SRC_DIR)main.c
SRC             += $(SRC_DIR)mem_clean.c
SRC             += $(SRC_DIR)op_add.c
SRC             += $(SRC_DIR)op_aff.c
SRC             += $(SRC_DIR)op_and.c
SRC             += $(SRC_DIR)op_fork.c
SRC             += $(SRC_DIR)op_ld.c
SRC             += $(SRC_DIR)op_ldi.c
SRC             += $(SRC_DIR)op_lfork.c
SRC             += $(SRC_DIR)op_live.c
SRC             += $(SRC_DIR)op_lld.c
SRC             += $(SRC_DIR)op_lldi.c
SRC             += $(SRC_DIR)op_or.c
SRC             += $(SRC_DIR)op_st.c
SRC             += $(SRC_DIR)op_sti.c
SRC             += $(SRC_DIR)op_sub.c
SRC             += $(SRC_DIR)op_xor.c
SRC             += $(SRC_DIR)op_zjmp.c
SRC             += $(SRC_DIR)op.c
SRC             += $(SRC_DIR)player_id.c
SRC             += $(SRC_DIR)player.c
SRC             += $(SRC_DIR)players.c
SRC             += $(SRC_DIR)printer.c
SRC             += $(SRC_DIR)get_val.c
SRC             += $(SRC_DIR)check_live_carriage.c

# project object files

OBJ		        = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

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

HEAD            := $(INC_DIR)lem-in.h
HEADER_FLAGS    := -I $(INC_DIR) -I $(LIBFT_INC)

# compiler

CC              := gcc

# rules

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME) -fsanitize=undefined

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CC_FLAGS) -c $< -o $@ $(HEADER_FLAGS)

$(LIB):
	make -C $(LIBFT_DIR)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

reclean: fclean all
	rm -f $(OBJ)
