#include "asm.h"
#include "commands.h"

void	write_words(t_asm *the_asm, t_line **line)
{
	char	*s;
	int		i;
	int		start;
	int		len;
	int		met_sep;
	int		met_label;

	s = (*line)->str;
	i = 0;
	printf("[%s]\n", s);

	int w_i;
	w_i = 0;
	met_label = 0;
	while (w_i < MAX_WORDS_N)
	{
		if (w_i == 0)
		{
			while (s[i] != '\0' && (s[i] == ' '|| s[i] == '\t') &&
			s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
				i++;
			start = i;
			len = 0;
			while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' &&
			s[i] != LABEL_CHAR && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
			{
				len++;
				i++;
			}
			if (s[i] == LABEL_CHAR)
			{
				//printf("WE MET LABEL\n");
				met_label = 1;
				len++;
				i++;
			}
		}
		else
		{
			while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t') &&
			s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
				i++;
			if (s[i] == SEPARATOR_CHAR && met_label && w_i == 1)
			{
				printf("Separator char after label.\n");
				exit(0);
			}
			//
			if (s[i] == SEPARATOR_CHAR && !met_label && w_i == 1)
			{
				printf("Separator char after command.\n");
				exit(0);
			}
			//
			if (s[i] == SEPARATOR_CHAR && met_label && w_i == 2)
			{
				printf("Separator char after command.\n");
				exit(0);
			}
			//
			met_sep = 0;
			start = i;
			len = 0;
			while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' &&
			s[i] != SEPARATOR_CHAR && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
			{
				len++;
				i++;
			}
			if (s[i] == SEPARATOR_CHAR)
			{
				met_sep = 1;
				i++;
			}
			if (s[i] == SEPARATOR_CHAR)
				ERROR(MANY_SEPARATORS, the_asm->curr_line_n);
			//ERROR WHEN NO SEPARATOR CHAR WHERE IT SHOULD BE
			//if (!met_sep && met_label && w_i == 3)
			// {
			// 	printf("No separator char after argument.\n");
			// 	exit(0);
			// }
			//printf("DID NOT MEET SEPARATOR\n");
			//
			if (len == 0 && met_sep == 1)
			{
				while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t') &&
				s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)//SKIP BLANKS
					i++;
				start = i;
				len = 0;
				while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' &&
				s[i] != SEPARATOR_CHAR && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)//THE WORD ITSELF
				{
					len++;
					i++;
				}
				if (s[i] == SEPARATOR_CHAR)
					i++;
				if (s[i] == SEPARATOR_CHAR)
					ERROR(MANY_SEPARATORS, the_asm->curr_line_n);
			}
		}
		the_asm->line_words[w_i] = ft_strsub(s, start, len);
		w_i++;
	}
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] != '\0' && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
		ERROR(WRONG_SMBLS_AT_END, the_asm->curr_line_n);
	//OUTPUT OF RECEIVED 5 WORDS -- DELETE LATER
	int k = 0;
	while (k < MAX_WORDS_N)
	{
		printf("\tWORD %i: [%s]\n", k + 1, the_asm->line_words[k]);
		k++;
	}
}

int		check_label(t_asm *the_asm, char *s)
{
	int i;
	int j;
	int is_match;

	i = 0;
	if (s[i] == LABEL_CHAR)
		ERROR(EMPTY_LABEL, the_asm->curr_line_n);
	while (s[i] != '\0' && s[i] != LABEL_CHAR)
	{
		j = 0;
		is_match = 0;
		while (LABEL_CHARS[j] != '\0')
		{
			if (s[i] == LABEL_CHARS[j])
				is_match = 1;
			j++;
		}
		if (is_match == 0)
			ERROR(LABEL_WRONG_CHAR, the_asm->curr_line_n);
		i++;
	}
	return (1);
}

int		check_t_reg(t_asm *the_asm, char *s)
{
	int i;

	i = 1;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			ERROR(WRONG_ARG_SNTX, the_asm->curr_line_n);
		i++;
	}
	if (ft_atoi(&s[1]) > REG_NUMBER || ft_atoi(&s[1]) == 0)
		ERROR(INCORRECT_REG, the_asm->curr_line_n);
	return (1);
}

int		check_t_dir(t_asm *the_asm, char *s)
{
	int i;

	i = 1;
	if (s[i] == LABEL_CHAR)
		return (check_label(the_asm, &s[i + 1]));
	else 
	{
		if (s[i] == '-')
			i++;
		while (s[i] != '\0')
		{
			if (!ft_isdigit(s[i]))
				ERROR(WRONG_ARG_SNTX, the_asm->curr_line_n);
			i++;
		}
	}
	return (1);
}

int		check_t_ind(t_asm *the_asm, char *s)
{
	int i;

	i = 0;
	if (s[i] == LABEL_CHAR)
		return (check_label(the_asm, &s[i + 1]));
	else 
	{
		if (s[i] == '-')
			i++;
		while (s[i] != '\0')
		{
			if (!ft_isdigit(s[i]))
				ERROR(WRONG_ARG_SNTX, the_asm->curr_line_n);
			i++;
		}
	}
	return (1);
}

void	check_args(t_asm *the_asm, int i, int shift)
{
	if (the_asm->line_words[i + shift][0] == 'r')
		check_t_reg(the_asm, the_asm->line_words[i + shift]);
	else if (the_asm->line_words[i + shift][0] == DIRECT_CHAR)
		check_t_dir(the_asm, the_asm->line_words[i + shift]);
	else if (the_asm->line_words[i + shift][0] == '-' || ft_isdigit(the_asm->line_words[i + shift][0]) ||
		the_asm->line_words[i + shift][0] == LABEL_CHAR)
		check_t_ind(the_asm, the_asm->line_words[i + shift]);
	else
		ERROR(WRONG_ARG_SNTX, the_asm->curr_line_n);
	i++;
}

int		check_if_words_correct(t_asm *the_asm, t_line **line)
{
	int	words;
	int first_is_label;
	int i;
	int found_command;

	words = 0;
	i = 0;
	while (i < MAX_WORDS_N)
	{
		if (the_asm->line_words[i][0] != '\0')
			words++;
		i++;
	}
	first_is_label = 0;
	if (ft_strchr(the_asm->line_words[0], LABEL_CHAR))
	{
		check_label(the_asm, the_asm->line_words[0]);
		first_is_label = 1;
	}
	else
	{
		i = 0;
		found_command = 0;
		while (i < COMMANDS_N)
		{
			if (!ft_strcmp(the_asm->line_words[0], commands[i].name))
				found_command = 1;
			i++;
		}
		if (!found_command)
			ERROR(WRONG_COMMAND, the_asm->curr_line_n);
	}
	if (first_is_label)
	{
		if (words == 1)
			return (1);
		if (words == 2)
			ERROR(NO_ARGS, the_asm->curr_line_n)
		i = 0;
		found_command = 0;
		while (i < COMMANDS_N)
		{
			if (!ft_strcmp(the_asm->line_words[1], commands[i].name))
				found_command = 1;
			i++;
		}
		if (!found_command)
			ERROR(WRONG_COMMAND, the_asm->curr_line_n);
		i = 0;
		while (i < words - 2)
		{
			check_args(the_asm, i, 2);
			i++;
		}
	}
	else
	{
		if (words == 1)
			ERROR(NO_ARGS, the_asm->curr_line_n);
		if (words == 5)
			ERROR(TOO_MANY_ARGS, the_asm->curr_line_n);
		i = 0;
		while (i < words - 1)
		{
			check_args(the_asm, i, 1);
			i++;
		}
		
	}
	//CHECKING IF WE HAVE THE CORRESPONDING NUMBER OF SEPARATOR CHARS AND WORDS
	//MAKE IT A SEPARATE FUNCTION LATER

	// int sep_chars;
	char *s;

	// sep_chars = 0;
	i = 0;
	s = (*line)->str;
	//printf("START OF CHECKING...\n");
	if (first_is_label)
	{
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != LABEL_CHAR)
			i++;
		i++;//WENT PAST LABEL

		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
			i++;//WENT PAST COMMAND

		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)
			i++;//WENT PAST FIRST ARG
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;

		if (s[i] == SEPARATOR_CHAR && words == 3)
		{
			printf("Wrong number of separator chars.\n");
			exit(0);
		}
		//
		if (s[i] != SEPARATOR_CHAR && words >= 4)
		{
			printf("Wrong number of separator chars.\n");
			exit(0);
		}
		//
		if (s[i] == SEPARATOR_CHAR)
			i++;//','

		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)
			i++;//WENT PAST SECOND ARG
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (s[i] == SEPARATOR_CHAR && words == 4)
		{
			printf("Wrong number of separator chars.\n");
			exit(0);
		}
		if (s[i] != SEPARATOR_CHAR && words == 5)
		{
			printf("Wrong number of separator chars.\n");
			exit(0);
		}
		if (s[i] == SEPARATOR_CHAR)
			i++;//','
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)
			i++;//WENT PAST THIRD ARG
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		//printf("%s\n", &s[i]);
		if (s[i] == SEPARATOR_CHAR && words == 5)
		{
		  	printf("Wrong number of separator chars.\n");
		  	exit(0);
		}
		// printf("%s\n", &s[i]);
	}
	else
	{
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
			i++;//WENT PAST COMMAND

		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)
			i++;//WENT PAST FIRST ARG
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;

		if (s[i] == SEPARATOR_CHAR && words == 2)
		{
			printf("Wrong number of separator chars.\n");
			exit(0);
		}
		//
		if (s[i] != SEPARATOR_CHAR && words >= 3)
		{
			printf("Wrong number of separator chars.\n");
			exit(0);
		}
		//
		if (s[i] == SEPARATOR_CHAR)
			i++;//','

		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)
			i++;//WENT PAST SECOND ARG
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (s[i] == SEPARATOR_CHAR && words == 3)
		{
			printf("Wrong number of separator chars.\n");
			exit(0);
		}
		if (s[i] != SEPARATOR_CHAR && words == 4)
		{
			printf("Wrong number of separator chars.\n");
			exit(0);
		}
		if (s[i] == SEPARATOR_CHAR)
			i++;//','
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)
			i++;//WENT PAST THIRD ARG
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		//printf("%s\n", &s[i]);
		if (s[i] == SEPARATOR_CHAR && words == 4)
		{
		  	printf("Wrong number of separator chars.\n");
		  	exit(0);
		}
		// printf("%s\n", &s[i]);
	}
	return (first_is_label);
}

void	add_cmnd_line(t_asm *the_asm)
{
	if (!the_asm->e_c_l)
		the_asm->e_c_l = new_exec_code_line(the_asm->last_cmnd_id);
	else
	{
		the_asm->e_c_l->next = new_exec_code_line(the_asm->last_cmnd_id);
		the_asm->e_c_l = the_asm->e_c_l->next;
	}
	if (!the_asm->e_c_l_top)
		the_asm->e_c_l_top = the_asm->e_c_l;
	the_asm->last_cmnd_id++;
}

void	add_label(t_asm *the_asm)
{
	if (!the_asm->labels)
		the_asm->labels = new_label(the_asm->line_words[0]);
	else
	{
		the_asm->labels->next = new_label(the_asm->line_words[0]);
		the_asm->labels = the_asm->labels->next;
	}
	if (!the_asm->labels_top)
		the_asm->labels_top = the_asm->labels;
}

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
	int i;

	i = 0;
	while (i < COMMANDS_N)
	{
		if (!ft_strcmp(the_asm->line_words[index],
		commands[i].name))
		{
			the_asm->e_c_l->cmnd_code = commands[i].id;
			printf("COMMAND: %s\n", commands[i].name);
			break ;
		}
		i++;
	}
	//ARG_1
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

int		count_label_byte_at(t_asm *the_asm)
{
	int i;
	int id;
	int byte_at;
	t_exec_code_line *cmnd_line;

	i = 0;
	id = the_asm->last_cmnd_id;
	byte_at = 0;
	cmnd_line = the_asm->e_c_l_top;
	while (i < id && cmnd_line)
	{
		byte_at += cmnd_line->cmnd_size;
		cmnd_line = cmnd_line->next;//AVOID SEGV HERE
		i++;
	}
	return (byte_at);
}

void	check_command_line(t_asm *the_asm, t_line **line)
{
	int first_is_label;
	int index;

	if (!is_empty_or_comment(line))
	{
		write_words(the_asm, line);
		first_is_label = check_if_words_correct(the_asm, line);
		if (first_is_label)
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
		{
			add_cmnd_line(the_asm);
			fill_cmnd_line_info(the_asm, index);
		}
		//ADD COMMAND LINE
		//WRITE IT TO STRUCTURE
	}
}