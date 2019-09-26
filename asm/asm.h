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

typedef struct	s_asm
{
	char	*header;
	char	*champion_name;
	int		exec_code_size;
	char	*champion_comment;
	char	*exec_code;
	char	*dot_s_name;
	char	*dot_s_file_name;
}				t_asm;

void			check_input(int argc, char **argv, t_asm *the_asm);

int				read_from_dot_s(t_asm *the_asm);
void			parse_line(t_asm *the_asm, char *s);
void			check_name(t_asm *the_asm, char *s);
int				count_kavicki(char *s);
void			check_comment(t_asm *the_asm, char *s);
void			check_text_comment(char **s);

void			write_to_dot_cor(t_asm *the_asm);

t_asm			*new_asm(void);

#endif