#include "asm.h"

void	parse_line(t_asm *the_asm, char *s)
{
	the_asm->exec_code_size = 1;
	printf("[%s]\n", s);
	if (ft_strstr(s, NAME_CMD_STRIN))
		printf("\tFOUND NAME\n");
	else if (ft_strstr(s, COMMENT_CMD_STRING))
		printf("\tFOUND COMMENT\n");
	else
		printf("\tFOUND EITHER LBL, CMND, LBL + CMND or EMPTY\n");
}