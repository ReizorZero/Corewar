NAME = asm

SRCF = main.c check_asm_input.c new_elements.c read_from_dot_s.c write_to_dot_cor.c \
       parse_lines.c check_name.c check_comment.c check_command_line.c add_elements.c \
	   write_cmnd_line_words.c check_if_words_correct.c label_tools.c check_args_types.c \
	   functions.c args_types_tools.c comment_tools.c words_tools.c words_tools_2.c \
	   name_tools.c cmnd_line_tools.c cmnd_line_tools_2.c 

LIB = ../libft/libft.a

CC = gcc

CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCF)
	$(CC) $(CFLAG) -o $(NAME) $(SRCF) $(LIB)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all