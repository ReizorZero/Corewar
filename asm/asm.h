#ifndef ASM_H
# define ASM_H

# include "../op.h"
# include "../libft/inc/libft.h"
# include <stdio.h> //DELETE THEN
# include <fcntl.h>

# define ERROR(X, Y) {printf(X, Y);exit(0);}
# define ERROR_(X) {printf(X);exit(0);}

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
//# define LABEL_CHAR_POSITON "Label char should be after label name.\n"

# define MANY_SEPARATORS "Found 2 or more separator char in a row. (Line %i)\n"

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
	int		arg_n;
	int		arg_1_types[3];//or replace with int *arg_1_types, but better not
	int		arg_2_types[3];
	int		arg_3_types[3];
	//maybe add args_size later
}				t_commands_info;

typedef struct	s_exec_code_line
{
	int							cmnd_code;
	int							arg_1_code;
	int							arg_1_value;
	int							arg_2_code;
	int							arg_2_value;
	int							arg_3_code;
	int							arg_3_value;
	int							has_label;
	char						**label_name;
	int							label_n;
	int							*label_size;
	struct s_exec_code_line		*next;
}				t_exec_code_line;

typedef struct	s_labels
{
	char			*name;
	int				byte_at;
	struct s_labels	*next;
}				t_labels;

typedef struct	s_line
{
	struct s_line	*next;
	char			*str;
}				t_line;

typedef struct	s_asm
{
	int					fd;
	char				*champion_name;
	int					exec_code_size;
	char				*champion_comment;
	char				*exec_code;
	char				*dot_s_name;
	char				*dot_s_file_name;
	t_exec_code_line	*e_c_l;
	t_exec_code_line	*e_c_l_top;
	t_line				*lines;
	t_line				*lines_top;
	char				**line_words;
	int					curr_line_n;
}				t_asm;

void			check_input(int argc, char **argv, t_asm *the_asm);

int				read_from_dot_s(t_asm *the_asm);
void			parse_lines(t_asm *the_asm);
void			check_name(t_asm *the_asm, t_line **line);
int				count_kavichki(char *s);
void			check_comment(t_asm *the_asm, t_line **line);
void			check_text_comment(char **s);
void			check_command_line(t_asm *the_asm, t_line **line);

void			write_to_dot_cor(t_asm *the_asm);

t_asm			*new_asm(void);
t_line			*new_line(char *str);

char			**tabs_split(char const *s);

#endif