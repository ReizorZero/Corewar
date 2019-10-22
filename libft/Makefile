# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshvets <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 16:47:12 by mshvets           #+#    #+#              #
#    Updated: 2018/12/12 14:38:22 by mshvets          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of the executable file

NAME		= libft.a

# project directories

SRC_DIR     = ./src/
OBJ_DIR     = ./obj/
INC_DIR     = ./inc/

# lib source files
FUNCTIONS	:= $(SRC_DIR)ft_atoi.c
FUNCTIONS	+= $(SRC_DIR)ft_bzero.c
FUNCTIONS	+= $(SRC_DIR)ft_isalnum.c
FUNCTIONS	+= $(SRC_DIR)ft_isalpha.c
FUNCTIONS	+= $(SRC_DIR)ft_isascii.c
FUNCTIONS	+= $(SRC_DIR)ft_isdigit.c
FUNCTIONS	+= $(SRC_DIR)ft_isprint.c
FUNCTIONS	+= $(SRC_DIR)ft_itoa.c
FUNCTIONS	+= $(SRC_DIR)ft_lstadd.c
FUNCTIONS	+= $(SRC_DIR)ft_lstdel.c
FUNCTIONS	+= $(SRC_DIR)ft_lstdelone.c
FUNCTIONS	+= $(SRC_DIR)ft_lstiter.c
FUNCTIONS	+= $(SRC_DIR)ft_lstmap.c
FUNCTIONS	+= $(SRC_DIR)ft_lstnew.c
FUNCTIONS	+= $(SRC_DIR)ft_memalloc.c
FUNCTIONS	+= $(SRC_DIR)ft_memccpy.c
FUNCTIONS	+= $(SRC_DIR)ft_memchr.c
FUNCTIONS	+= $(SRC_DIR)ft_memcmp.c
FUNCTIONS	+= $(SRC_DIR)ft_memcpy.c
FUNCTIONS	+= $(SRC_DIR)ft_memdel.c
FUNCTIONS	+= $(SRC_DIR)ft_memmove.c
FUNCTIONS	+= $(SRC_DIR)ft_memset.c
FUNCTIONS	+= $(SRC_DIR)ft_putchar_fd.c
FUNCTIONS	+= $(SRC_DIR)ft_putchar.c
FUNCTIONS	+= $(SRC_DIR)ft_putendl_fd.c
FUNCTIONS	+= $(SRC_DIR)ft_putendl.c
FUNCTIONS	+= $(SRC_DIR)ft_putnbr_fd.c
FUNCTIONS	+= $(SRC_DIR)ft_putnbr.c
FUNCTIONS	+= $(SRC_DIR)ft_putstr_fd.c
FUNCTIONS	+= $(SRC_DIR)ft_putstr.c
FUNCTIONS	+= $(SRC_DIR)ft_strcat.c
FUNCTIONS	+= $(SRC_DIR)ft_strchr.c
FUNCTIONS	+= $(SRC_DIR)ft_strclr.c
FUNCTIONS	+= $(SRC_DIR)ft_strcmp.c
FUNCTIONS	+= $(SRC_DIR)ft_strcpy.c
FUNCTIONS	+= $(SRC_DIR)ft_strdel.c
FUNCTIONS	+= $(SRC_DIR)ft_strdup.c
FUNCTIONS	+= $(SRC_DIR)ft_strequ.c
FUNCTIONS	+= $(SRC_DIR)ft_striter.c
FUNCTIONS	+= $(SRC_DIR)ft_striteri.c
FUNCTIONS	+= $(SRC_DIR)ft_strjoin.c
FUNCTIONS	+= $(SRC_DIR)ft_strlcat.c
FUNCTIONS	+= $(SRC_DIR)ft_strlen.c
FUNCTIONS	+= $(SRC_DIR)ft_strmap.c
FUNCTIONS	+= $(SRC_DIR)ft_strmapi.c
FUNCTIONS	+= $(SRC_DIR)ft_strncat.c
FUNCTIONS	+= $(SRC_DIR)ft_strncmp.c
FUNCTIONS	+= $(SRC_DIR)ft_strncpy.c
FUNCTIONS	+= $(SRC_DIR)ft_strnequ.c
FUNCTIONS	+= $(SRC_DIR)ft_strnew.c
FUNCTIONS	+= $(SRC_DIR)ft_strnstr.c
FUNCTIONS	+= $(SRC_DIR)ft_strrchr.c
FUNCTIONS	+= $(SRC_DIR)ft_strsplit.c
FUNCTIONS	+= $(SRC_DIR)ft_strstr.c
FUNCTIONS	+= $(SRC_DIR)ft_strsub.c
FUNCTIONS	+= $(SRC_DIR)ft_strtrim.c
FUNCTIONS	+= $(SRC_DIR)ft_tolower.c
FUNCTIONS	+= $(SRC_DIR)ft_toupper.c
FUNCTIONS   += $(SRC_DIR)ft_lstaddr.c
FUNCTIONS   += $(SRC_DIR)ft_isspace.c
FUNCTIONS	+= $(SRC_DIR)ft_cntwrd.c
FUNCTIONS	+= $(SRC_DIR)ft_srtwrd.c
FUNCTIONS	+= $(SRC_DIR)ft_numlen.c
FUNCTIONS	+= $(SRC_DIR)ft_pow.c
FUNCTIONS	+= $(SRC_DIR)ft_strupcase.c
FUNCTIONS	+= $(SRC_DIR)ft_strlowcase.c
FUNCTIONS	+= $(SRC_DIR)ft_itoa_base.c
FUNCTIONS	+= $(SRC_DIR)ft_sqrt.c
FUNCTIONS	+= $(SRC_DIR)get_next_line.c
FUNCTIONS	+= $(SRC_DIR)ft_printf.c
FUNCTIONS	+= $(SRC_DIR)ft_strjoinl.c
FUNCTIONS	+= $(SRC_DIR)ft_numinstr.c
FUNCTIONS	+= $(SRC_DIR)ft_uitoa_base.c
FUNCTIONS	+= $(SRC_DIR)ft_ftoa.c
FUNCTIONS	+= $(SRC_DIR)printf_specificator.c
FUNCTIONS	+= $(SRC_DIR)printf_specificator2.c
FUNCTIONS	+= $(SRC_DIR)printf_pointer.c
FUNCTIONS	+= $(SRC_DIR)printf_str.c
FUNCTIONS	+= $(SRC_DIR)printf_int.c
FUNCTIONS	+= $(SRC_DIR)printf_float_double.c
FUNCTIONS	+= $(SRC_DIR)printf_oux.c
FUNCTIONS	+= $(SRC_DIR)ft_check_sign_double.c
FUNCTIONS	+= $(SRC_DIR)ft_doublstrdel.c
FUNCTIONS	+= $(SRC_DIR)ft_cntchr.c
FUNCTIONS	+= $(SRC_DIR)ft_strdeli.c

# lib object files

OBJ		        = $(FUNCTIONS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# compilation flags

CC_FLAGS        := -Wall -Wextra -Werror

# header flags

HEAD            := $(INC_DIR)libft.h
HEADER_FLAGS    := -I $(INC_DIR)

# compiler

CC              := gcc

# rules

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@rm -f libft.h.gch

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CC_FLAGS) -c $< -o $@ $(HEADER_FLAGS)

clean:
#	rm -rf $(OBJ_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

reclean: fclean all
	rm -f $(OBJ)
