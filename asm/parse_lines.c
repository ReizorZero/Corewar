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
	{
		printf("No executable code...\n");
		exit(0);
	}
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
			{
				printf("Name not at start\n");
				exit(0);
			}
			if (!the_asm->champion_name)
				check_name(the_asm, &lines);
			else
			{
				printf("Name second time\n");
				exit(0);
			}
		}
		else if (ft_strstr(lines->str, COMMENT_CMD_STRING))
		{
			if (the_asm->e_c_l_top)
			{
				printf("Comment not at start\n");
				exit(0);
			}
			if (!the_asm->champion_comment)
				check_comment(the_asm, &lines);
			else
			{
				printf("Comment second time\n");
				exit(0);
			}
		}
		else
			check_command_line(the_asm, &lines);
		the_asm->curr_line_n++;
		lines = lines->next;
	}
	if (!the_asm->champion_name)
	{
		printf("No champ name...\n");
		exit(0);
	}
	if (!the_asm->champion_comment)
	{
		printf("No champ comment...\n");
		exit(0);
	}
	if (!the_asm->e_c_l_top)// || the_asm->exec_code_size == 0)
	{
		printf("No executable code...\n");
		exit(0);
	}
	fill_labels_args(the_asm);
	count_exec_size(the_asm);
}