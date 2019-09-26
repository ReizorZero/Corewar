#ifndef ASM_H
# define ASM_H

# include "../op.h"
# include "../libft/inc/libft.h"
# include <stdio.h> //DELETE THEN
# include <fcntl.h>

typedef struct  s_asm
{
    char    *header;
    char    *champion_name;
    int     exec_code_size;
    char    *champion_comment;
    char    *exec_code;
    char    *dot_s_name;
    char    *dot_s_file_name;
}               t_asm;

void	check_input(int argc, char **argv, t_asm *the_asm);
int		read_from_dot_s(t_asm *the_asm);
void	parse_line(t_asm *the_asm, char *s);
void	write_to_dot_cor(t_asm *the_asm);

t_asm   *new_asm(void);

#endif