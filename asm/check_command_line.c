#include "asm.h"
//#include "commands.h"

int		is_empty_or_comment(t_line **line)
{
	int		i;
	char	*s;

	i = 0;
	s = (*line)->str;
	if (s[0] == '\0')
		return (1);
	while (s[i] != '\0' && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	fill_cmnd_line_info(t_asm *the_asm, int index)
{
	if (the_asm->line_words[index + 1][0] == 'r')
	{
		the_asm->e_c_l->arg_1_code = REG_CODE;
		the_asm->e_c_l->arg_1_value = ft_atoi(&the_asm->line_words[index + 1][1]);
		printf("ARG_1: %i\n", the_asm->e_c_l->arg_1_value);
	}
	else if (the_asm->line_words[index + 1][0] == '%')
	{
		the_asm->e_c_l->arg_1_code = DIR_CODE;
		//IF IT IS NOT LABEL
		the_asm->e_c_l->arg_1_value = ft_atoi(&the_asm->line_words[index + 1][1]);
		//IF IT IS A LABEL, FIND THE CORRESPONDING LABEL IN LABELS LIST
		//AND WRITE ITS BYTE_AT VALUE
		printf("ARG_1: %i\n", the_asm->e_c_l->arg_1_value);
	}
	else
	{
		the_asm->e_c_l->arg_1_code = IND_CODE;
		//IF IT IS NOT LABEL
		the_asm->e_c_l->arg_1_value = ft_atoi(&the_asm->line_words[index + 1][0]);
		//IF IT IS A LABEL, FIND THE CORRESPONDING LABEL IN LABELS LIST
		//AND WRITE ITS BYTE_AT VALUE
		printf("ARG_1: %i\n", the_asm->e_c_l->arg_1_value);
	}
	printf("ARG_1 TYPE: %i\n", the_asm->e_c_l->arg_1_code);
	//CHECK IF THE TYPES OF ARGS ARE CORRESPONDING WITH THE COMMAND
	int k;
	int found_type;
	k = 0;
	found_type = 0;
	while (k < 3)
	{
		if (the_asm->e_c_l->arg_1_code == commands[the_asm->e_c_l->cmnd_code - 1].arg_1_types[k])
		{
			printf("type = %i\n", commands[the_asm->e_c_l->cmnd_code - 1].arg_1_types[k]);
			found_type = 1;
			break ;
		}
		printf("type @ %i\n", commands[the_asm->e_c_l->cmnd_code - 1].arg_1_types[k]);
		k++;
	}
	if (!found_type)
	{
		printf("Wrong arg_1 type.\n");
		exit (0);
	}
	//DO THE SAME FOR THE REST 2 ARGS: ARG_2, ARG_3
	the_asm->e_c_l->cmnd_size = 1 + commands[the_asm->e_c_l->cmnd_code - 1].has_arg_types_code +
	the_asm->e_c_l->arg_1_size + the_asm->e_c_l->arg_2_size + the_asm->e_c_l->arg_3_size;
}

void	check_command_line(t_asm *the_asm, t_line **line)
{
	//int first_is_label;
	int index;

	if (!is_empty_or_comment(line))
	{
		add_cmnd_line(the_asm);
		write_cmnd_line_words(the_asm, line);
		//first_is_label = check_if_words_correct(the_asm, line);
		check_if_words_correct(the_asm, line);
		//if (first_is_label)
		if (the_asm->e_c_l->first_is_label)
		{

			//IF WE HAVE LABEL
			//CREATE NEW LABEL
			add_label(the_asm);
			//COUNT SIZE OF COMMANDS BEFORE
			//count_label_byte_at(the_asm);//add here or manually:
			//the_asm->labels->byte_at = count_label_byte_at(the_asm);
			if (the_asm->line_words[1][0] == '\0')
				index = -1;
			else
				index = 1;
		}
		else
			index = 0;
		if (index > -1)
		//{
			//add_cmnd_line(the_asm);
			fill_cmnd_line_info(the_asm, index);
		//}
		//ADD COMMAND LINE
		//WRITE IT TO STRUCTURE
	}
}