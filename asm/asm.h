#ifndef ASM_H
# define ASM_H

# include "../op.h"
# include "../libft/inc/libft.h"
# include <stdio.h> //DELETE THEN
# include <fcntl.h>

# define ERROR(X, Y) {printf(X, Y);exit(0);}
# define ERROR_(X) {printf(X);exit(0);}
# define USAGE(X, Y) {printf(X);printf(Y);exit(0);}

# define USAGE_INFO_1 "Usage: ./asm <sourcefile.s>\n"
# define USAGE_INFO_2 "\t(Note that only one file should be passed to input).\n"

# define TOO_MANY_FILES "Too many files. You should enter only one file at a time.\n"
# define NO_FILE_NAME "File name is missing.\n"
# define NO_FILE_EXTENSION "File extension is missing.\n"
# define WRONG_FILE_EXTENSION "File extension is wrong.\n"

# define KAVICHKI_NUMBER "Wrong number of \" symbols. (Line %i)\n"

# define NO_CHAMP_NAME "No champion name after .name (Line %i)\n"
# define SMBLS_CHAMP_NAME "Wrong symbols after champion name. (Line %i)\n"
# define SYMBOLS_CMND_NAME "Wrong symbols before/after .name (Line %i)\n"
# define CLSNG_QT_CHAMP_NAME "No closing quote for champion name. (Line %i)\n"

# define NO_COMMENT "No comment after .comment (Line %i)\n"
# define SYMBOLS_COMMENT "Should't be any symbols after comment. (Line %i)\n"
# define SYMBOLS_CMND_COMMENT "Wrong symbols before/after .comment (Line %i)\n"
# define NO_CLSNG_QT_COMMENT "No closing quote for comment. (Line %i)\n"

# define LABEL_WRONG_CHAR "Label contains wrong char. (Line %i)\n"
# define EMPTY_LABEL "Label name missing. (Line %i)\n"

# define MANY_SEPARATORS "Found 2 or more separator char in a row. (Line %i)\n"
# define WRONG_N_SEPARATORS "Wrong number of separator chars. (Line %i)\n"
# define SEPARATOR_AFTER_LABEL "Separator char after label. (Line %i)\n"
# define SEPARATOR_AFTER_CMND "Separator char after command. (Line %i)\n"

# define WRONG_SMBLS_AT_END "Wrong symbols at the end of the line. (Line %i)\n"

# define WRONG_COMMAND "Wrong command. (Line %i)\n"
# define NO_ARGS "No arguments after command. (Line %i)\n"
# define TOO_MANY_ARGS "Too many arguments after command. (Line %i)\n"
# define WRONG_ARG_SNTX "Wrong argument syntax. (Line %i)\n"
# define WRONG_ARG_TYPE "Wrong argument type. (Line %i)\n"
# define INCORRECT_REG "Registry number is incorrect. (Line %i)\n"

# define LIVE_ID	1
# define LD_ID		2
# define ST_ID		3
# define ADD_ID		4
# define SUB_ID		5
# define AND_ID		6
# define OR_ID		7
# define XOR_ID		8
# define ZJMP_ID	9
# define LDI_ID		10
# define STI_ID		11
# define FORK_ID	12
# define LLD_ID		13
# define LLDI_ID	14
# define LFORK_ID	15
# define AFF_ID		16

# define MAX_WORDS_N 5
# define COMMANDS_N 16

typedef struct	s_commands_info
{
	int		id;
	char	*name;
	int		t_dir_size;
	int		has_arg_types_code;
	int		arg_n;
	int		arg_types[3][3];
	// int		arg_1_types[3];//or replace with int *arg_1_types, but better not
	// int		arg_2_types[3];
	// int		arg_3_types[3];
}				t_commands_info;

typedef struct	s_exec_code_line
{
	int							id;
	int							cmnd_code;
	int							arg_code[3];
	int							arg_value[3];
	int							arg_size[3];
	// int							arg_1_code;
	// int							arg_1_value;
	// int							arg_1_size;
	// int							arg_2_code;
	// int							arg_2_value;
	// int							arg_2_size;
	// int							arg_3_code;
	// int							arg_3_value;
	// int							arg_3_size;
	int							cmnd_size;
	int							first_is_label;
	int							words;
	//int							has_label;
	//char						**label_name;
	//int							label_n;
	//int							*label_size;
	struct s_exec_code_line		*next;
}				t_exec_code_line;

typedef struct	s_label
{
	char			*name;
	int				byte_at;
	struct s_label	*next;
}				t_label;

typedef struct	s_line
{
	struct s_line	*next;
	char			*str;
}				t_line;

typedef struct	s_asm
{
	int					fd;
	char				*dot_s_name;
	char				*dot_s_file_name;
	char				*champion_name;
	char				*champion_comment;
	int					exec_code_size;
	char				*exec_code;
	t_exec_code_line	*e_c_l;
	t_exec_code_line	*e_c_l_top;
	t_line				*lines;
	t_line				*lines_top;
	char				**line_words;
	t_label				*labels;
	t_label				*labels_top;
	int					curr_line_n;
	int					last_cmnd_id;
}				t_asm;

t_commands_info		commands[16];

void				check_asm_input(int argc, char **argv, t_asm *the_asm);

int					read_from_dot_s(t_asm *the_asm);
void				parse_lines(t_asm *the_asm);
void				check_name(t_asm *the_asm, t_line **line);
int					count_kavichki(char *s);
void				check_comment(t_asm *the_asm, t_line **line);
void				check_text_comment(char **s);
void				check_command_line(t_asm *the_asm, t_line **line);

void				write_cmnd_line_words(t_asm *the_asm, t_line **line);
int					check_if_words_correct(t_asm *the_asm, t_line **line);
int					check_label(t_asm *the_asm, char *s);
int					count_label_byte_at(t_asm *the_asm);
void				check_args(t_asm *the_asm, int i, int shift);

void				write_to_dot_cor(t_asm *the_asm);

void				write_line_to_list(t_asm *the_asm, char *s);
void				add_cmnd_line(t_asm *the_asm);
void				add_label(t_asm *the_asm);

t_asm				*new_asm(void);
t_line				*new_line(char *str);
t_exec_code_line	*new_exec_code_line(int id);
t_label				*new_label(char *name);

#endif