#include "asm.h"

void	parse_line(t_asm *the_asm, char *s)
{
	check_text_comment(&s);
	if (ft_strstr(s, NAME_CMD_STRIN))
		check_name(the_asm, s);
	else if (ft_strstr(s, COMMENT_CMD_STRING))
		check_comment(the_asm, s);
	else
		check_command(the_asm, s);
}