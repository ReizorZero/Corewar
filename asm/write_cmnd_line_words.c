#include "asm.h"

void	write_cmnd_line_words(t_asm *the_asm, t_line **line)
{//VSE LISHNIYE PEREMENNIYE TIPA MET_SEP SDELAT' POLYAMI STRUKTURY LINE
	char	*s;
	int		i;
	int		start;
	int		len;
	int		met_sep;
	int		met_label;
	int 	w_i;

	s = (*line)->str;
	i = 0;
	w_i = 0;
	met_label = 0;
	while (w_i < MAX_WORDS_N)
	{
		if (w_i == 0)
		{
			//SEPARATE
			while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t') &&
			s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
				i++;
			//
			start = i;
			len = 0;
			
			//SEPARATE
			while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' &&
			s[i] != LABEL_CHAR && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
			{
				len++;
				i++;
			}
			//

			//SEPARATE
			if (s[i] == LABEL_CHAR)
			{
				met_label = 1;
				the_asm->e_c_l->first_is_label = 1;
				len++;
				i++;
			}
			//
		}
		else
		{
			//SEPARATE
			while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t') &&
			s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR && s[i] != SEPARATOR_CHAR)
				i++;
			if (s[i] == SEPARATOR_CHAR && met_label && w_i == 1)
				ERROR(SEPARATOR_AFTER_LABEL, the_asm->curr_line_n);
			if (s[i] == SEPARATOR_CHAR && !met_label && w_i == 1)
				ERROR(SEPARATOR_AFTER_CMND, the_asm->curr_line_n);
			if (s[i] == SEPARATOR_CHAR && met_label && w_i == 2)
				ERROR(SEPARATOR_AFTER_CMND, the_asm->curr_line_n);
			//
			met_sep = 0;
			start = i;
			len = 0;
			//SEPARATE
			while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' &&
			s[i] != SEPARATOR_CHAR && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
			{
				len++;
				i++;
			}
			//

			//SEPARATE
			if (s[i] == SEPARATOR_CHAR)
			{
				met_sep = 1;
				i++;
			}
			//

			//SEPARATE
			if (s[i] == SEPARATOR_CHAR)
				ERROR(MANY_SEPARATORS, the_asm->curr_line_n);
			if (len == 0 && met_sep == 1)
			{
				while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t') &&
				s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
					i++;
				start = i;
				len = 0;
				while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' &&
				s[i] != SEPARATOR_CHAR && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
				{
					len++;
					i++;
				}
				if (s[i] == SEPARATOR_CHAR)
					i++;
				if (s[i] == SEPARATOR_CHAR)
					ERROR(MANY_SEPARATORS, the_asm->curr_line_n);
			}
			//
		}
		the_asm->line_words[w_i] = ft_strsub(s, start, len);
		w_i++;
	}
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] != '\0' && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
		ERROR(WRONG_SMBLS_AT_END, the_asm->curr_line_n);
}
