#include "asm.h"
#include "commands.h"

void	define_cmnd_type(t_asm *the_asm, int w_i)
{
	int i;
	int found_command;

	i = 0;
	found_command = 0;
	while (i < COMMANDS_N)
	{
		if (!ft_strcmp(the_asm->line_words[w_i], commands[i].name))
		{
			found_command = 1;
			break ;
		}
		i++;
	}
	the_asm->e_c_l->cmnd_code = commands[i].id;
	if (!found_command)
		ERROR(WRONG_COMMAND, the_asm->curr_line_n);
}

void	count_words_cmnd_line(t_asm *the_asm)
{
	int words;
	int i;

	words = 0;
	i = 0;
	while (i < MAX_WORDS_N)
	{
		if (the_asm->line_words[i][0] != '\0')
			words++;
		i++;
	}
	the_asm->e_c_l->words = words;
}

void	check_separators(t_asm *the_asm, t_line **line)
{
	char	*s;
	int		i;
	int		words;

	i = 0;
	s = (*line)->str;
	words = the_asm->e_c_l->words;
	
	if (the_asm->e_c_l->first_is_label)
	{
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != LABEL_CHAR)
			i++;
		i++;//WENT PAST LABEL
	}

	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)
		i++;//WENT PAST COMMAND
	if (s[i] == SEPARATOR_CHAR)
		ERROR(SEPARATOR_AFTER_CMND, the_asm->curr_line_n);

	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)
		i++;//WENT PAST FIRST ARG
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;

	if (s[i] == SEPARATOR_CHAR &&
	(words == 2 + the_asm->e_c_l->first_is_label))
		ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
	if (s[i] != SEPARATOR_CHAR &&
	(words >= 3 + the_asm->e_c_l->first_is_label))
		ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
	if (s[i] == SEPARATOR_CHAR)
		i++;//','

	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)
		i++;//WENT PAST SECOND ARG
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;

	if (s[i] == SEPARATOR_CHAR &&
	(words == 3 + the_asm->e_c_l->first_is_label))
		ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
	if (s[i] != SEPARATOR_CHAR &&
	(words == 4 + the_asm->e_c_l->first_is_label))
		ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
	if (s[i] == SEPARATOR_CHAR)
		i++;//','

	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)
		i++;//WENT PAST THIRD ARG
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	//printf("%s\n", &s[i]);
	if (s[i] == SEPARATOR_CHAR &&
	(words == 4 + the_asm->e_c_l->first_is_label))
		ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
	// printf("%s\n", &s[i]);
}

int		check_if_words_correct(t_asm *the_asm, t_line **line)
{
	int	words;
	int i;
	int shift;

	count_words_cmnd_line(the_asm);
	words = the_asm->e_c_l->words;
	if (the_asm->e_c_l->first_is_label)
	{
		check_label(the_asm, the_asm->line_words[0]);
		add_label(the_asm);
		the_asm->labels->cmnd_id_at = the_asm->e_c_l->id;
	}
	if (the_asm->e_c_l->first_is_label && words == 1)
	{
		the_asm->e_c_l->is_label_only = 1;
		the_asm->e_c_l->id = -the_asm->e_c_l->id;
		the_asm->labels->cmnd_id_at = -the_asm->e_c_l->id;
		the_asm->last_cmnd_id--;
		return (1);
	}
	if ((the_asm->e_c_l->first_is_label && words == 2) ||
	(!the_asm->e_c_l->first_is_label && words == 1))
		ERROR(NO_ARGS, the_asm->curr_line_n);
	if (!the_asm->e_c_l->first_is_label && words == 5)
		ERROR(TOO_MANY_ARGS, the_asm->curr_line_n);
	define_cmnd_type(the_asm, the_asm->e_c_l->first_is_label);
	shift = (the_asm->e_c_l->first_is_label) ? 2 : 1;
	i = 0;
	while (i < words - shift)
	{
		check_args(the_asm, i, shift);
		i++;
	}
	check_separators(the_asm, line);
	the_asm->e_c_l->has_arg_types_code = 
	commands[the_asm->e_c_l->cmnd_code - 1].has_arg_types_code;
	the_asm->e_c_l->cmnd_line_size = 1 +
	the_asm->e_c_l->has_arg_types_code +
	the_asm->e_c_l->arg_size[0] +
	the_asm->e_c_l->arg_size[1] +
	the_asm->e_c_l->arg_size[2];
	return (1);
}