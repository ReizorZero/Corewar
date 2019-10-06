#include "asm.h"

void	parse_lines(t_asm *the_asm)
{
	t_line *lines;

	lines = the_asm->lines_top;
	while (lines)
	{
		if (ft_strstr(lines->str, NAME_CMD_STRIN))
			check_name(the_asm, &lines);
		else if (ft_strstr(lines->str, COMMENT_CMD_STRING))
			check_comment(the_asm, &lines);
		else
			check_command_line(the_asm, &lines);
		the_asm->curr_line_n++;
		lines = lines->next;
	}
}