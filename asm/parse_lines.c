#include "asm.h"

void	count_exec_size(t_asm *the_asm)
{
	t_exec_code_line *ecl;

	ecl = the_asm->e_c_l_top;
	while (ecl)
	{
		the_asm->exec_code_size += ecl->cmnd_line_size;
		ecl = ecl->next;
	}
	if (the_asm->exec_code_size == 0)
		ERROR_(NO_EXEC_CODE);
}

void	parse_lines(t_asm *the_asm)
{
	t_line *lines;

	lines = the_asm->lines_top;
	while (lines)
	{
		if (ft_strstr(lines->str, NAME_CMD_STRIN))
		{
			if (the_asm->e_c_l_top)
				ERROR(NAME_NOT_A_S, the_asm->curr_line_n);
			if (!the_asm->champion_name)
				check_name(the_asm, &lines);
			else
				ERROR(NAME_TWICE, the_asm->curr_line_n);
		}
		else if (ft_strstr(lines->str, COMMENT_CMD_STRING))
		{
			if (the_asm->e_c_l_top)
				ERROR(COMMENT_NOT_A_S, the_asm->curr_line_n);
			if (!the_asm->champion_comment)
				check_comment(the_asm, &lines);
			else
				ERROR(COMMENT_TWICE, the_asm->curr_line_n);
		}
		else
			check_command_line(the_asm, &lines);
		the_asm->curr_line_n++;
		lines = lines->next;
	}
	if (!the_asm->champion_name)
		ERROR_(NO_NAME_AT_ALL);
	if (!the_asm->champion_comment)
		ERROR_(NO_COMMENT_AT_ALL);
	if (!the_asm->e_c_l_top)
		ERROR_(NO_EXEC_CODE);
	fill_labels_args(the_asm);
	count_exec_size(the_asm);
}