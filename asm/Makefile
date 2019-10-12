NAME = asm

SRCF = main.c check_asm_input.c new_elements.c read_from_dot_s.c write_to_dot_cor.c \
       parse_lines.c check_name.c check_comment.c check_command_line.c add_elements.c \
	   write_cmnd_line_words.c check_if_words_correct.c label_tools.c check_args_types.c functions.c

LIB = ../libft/libft.a

CC = gcc

CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCF)
	#make -C libft/ fclean && make -C libft/
	#make -C ft_printf/ fclean && make -C ft_printf/
	$(CC) $(CFLAG) -o $(NAME) $(SRCF) $(LIB)

clean:
	#make -C libft/ clean
	#make -C ft_printf/ clean
	/bin/rm -f *.o

fclean: clean
	#make -C libft/ fclean
	#make -C ft_printf/ fclean
	/bin/rm -f $(NAME)

re: fclean all