#include "asm.h"

void	count_exec_size(t_asm *the_asm)
{
	t_exec_code_line *ecl;

	ecl = the_asm->e_c_l_top;
	while (ecl)
	{
		//printf("@ cmnd_line_size: %i\n", ecl->cmnd_line_size);
		the_asm->exec_code_size += ecl->cmnd_line_size;
		ecl = ecl->next;
	}
	printf("exec_code_size = %i\n", the_asm->exec_code_size);
}

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
	fill_labels_args(the_asm);
	count_exec_size(the_asm);
}