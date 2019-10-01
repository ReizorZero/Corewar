#ifndef ASM_H
# define ASM_H

# include "../op.h"
# include "../libft/inc/libft.h"
# include <stdio.h> //DELETE THEN
# include <fcntl.h>

# define ERROR(X) {printf(X);exit(0);}

# define KAVICHKI_NUMBER "Wrong number of \" symbols.\n"

# define NO_CHAMP_NAME "No champion name after .name\n"
# define SYMBOLS_CHAMP_NAME "Should't be any symbols after champion name.\n"
# define SYMBOLS_CMND_NAME "Wrong symbols before/after .name\n"

# define NO_COMMENT "No comment after .comment\n"
# define SYMBOLS_COMMENT "Should't be any symbols after comment.\n"
# define SYMBOLS_CMND_COMMENT "Wrong symbols before/after .comment\n"

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

typedef struct	s_commands_info
{
	int 	id;
	char	*name;
	int 	arg_n;
	int 	arg_1_types[3];//or replace with int *arg_1_types, but better not
	int 	arg_2_types[3];
	int 	arg_3_types[3];
	//maybe add args_size later
}				t_commands_info;

typedef struct	s_exec_code_line
{
	int 						cmnd_code;
	int 						arg_1_code;
	int 						arg_1_value;
	int 						arg_2_code;
	int 						arg_2_value;
	int 						arg_3_code;
	int 						arg_3_value;
	int 						has_label;
	char						*label_name;
	int 						label_size;
	struct s_exec_code_line		*next;
}				t_exec_code_line;

typedef struct	s_asm
{
	char				*header;
	char				*champion_name;
	int					exec_code_size;
	char				*champion_comment;
	char				*exec_code;
	char				*dot_s_name;
	char				*dot_s_file_name;
	t_exec_code_line	*e_c_l;
}				t_asm;

void			check_input(int argc, char **argv, t_asm *the_asm);

int				read_from_dot_s(t_asm *the_asm);
void			parse_line(t_asm *the_asm, char *s);
void			check_name(t_asm *the_asm, char *s);
int				count_kavicki(char *s);
void			check_comment(t_asm *the_asm, char *s);
void			check_text_comment(char **s);
void			check_command(t_asm *the_asm, char *s);

void			write_to_dot_cor(t_asm *the_asm);

t_asm			*new_asm(void);

#endif