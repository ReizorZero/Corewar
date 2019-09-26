#include "asm.h"

void	parse_line(t_asm *the_asm, char *s)
{
	the_asm->exec_code_size = 1;
	if (ft_strstr(s, NAME_CMD_STRIN))
		check_name(the_asm, s);
	else if (ft_strstr(s, COMMENT_CMD_STRING))
		check_comment(the_asm, s);
	else
	{
		printf("[%s]\n", s);
		printf("\tFOUND EITHER LBL, CMND, LBL + CMND or EMPTY\n");
	}
}