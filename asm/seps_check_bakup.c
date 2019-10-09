#include "asm.h"

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
			ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
		if (s[i] != SEPARATOR_CHAR && words >= 4)
			ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
		if (s[i] == SEPARATOR_CHAR)
			i++;//','

		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)
			i++;//WENT PAST SECOND ARG
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;

		if (s[i] == SEPARATOR_CHAR && words == 4)
			ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
		if (s[i] != SEPARATOR_CHAR && words == 5)
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
		if (s[i] == SEPARATOR_CHAR && words == 5)
			ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
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
			ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
		if (s[i] != SEPARATOR_CHAR && words >= 3)
			ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
		if (s[i] == SEPARATOR_CHAR)
			i++;//','

		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)
			i++;//WENT PAST SECOND ARG
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;

		if (s[i] == SEPARATOR_CHAR && words == 3)
			ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
		if (s[i] != SEPARATOR_CHAR && words == 4)
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
		if (s[i] == SEPARATOR_CHAR && words == 4)
			ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
		// printf("%s\n", &s[i]);
	}
}