#include "asm.h"

void	write_cmnd_line_words(t_asm *the_asm, t_line **line)
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
				met_label = 1;
				the_asm->e_c_l->first_is_label = 1;
				len++;
				i++;
			}
		}
		else
		{
			while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t') &&
			s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR && s[i] != SEPARATOR_CHAR)
				i++;
			if (s[i] == SEPARATOR_CHAR && met_label && w_i == 1)
				ERROR(SEPARATOR_AFTER_LABEL, the_asm->curr_line_n);
			if (s[i] == SEPARATOR_CHAR && !met_label && w_i == 1)
				ERROR(SEPARATOR_AFTER_CMND, the_asm->curr_line_n);
			if (s[i] == SEPARATOR_CHAR && met_label && w_i == 2)
				ERROR(SEPARATOR_AFTER_CMND, the_asm->curr_line_n);
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