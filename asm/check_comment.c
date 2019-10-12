#include "asm.h"

int		count_kavichki(char *s)
{
	int i;
	int kavichki;
	int	met_hash;

	i = 0;
	met_hash = 0;
	kavichki = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == COMMENT_CHAR || s[i] == ALT_COMMENT_CHAR) && (kavichki >= 2 || kavichki == 0))
		 	met_hash = 1;
		if (s[i] == '\"' && met_hash == 0)
			kavichki++;
		i++;
	}
	return (kavichki);
}

int		check_comment_cmnd_tag(t_asm *the_asm, char *s, int i)
{
	int cmnd_len;
	
	cmnd_len = 8;
	if (s[i] != '.' ||
	s[i + 1] != 'c' ||
	s[i + 2] != 'o' ||
	s[i + 3] != 'm' ||
	s[i + 4] != 'm' ||
	s[i + 5] != 'e' ||
	s[i + 6] != 'n' ||
	s[i + 7] != 't')
		ERROR(SYMBOLS_CMND_COMMENT, the_asm->curr_line_n);
	return (i + cmnd_len);
}

int		anything_after_dot_comment(t_asm *the_asm, char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && (s[i] == '\t' || s[i] == ' '))
			i++;
	i = check_comment_cmnd_tag(the_asm, s, i);
	while (s[i] != '\0' && s[i] != '\"' &&
	s[i] != ALT_COMMENT_CHAR &&
	s[i] != COMMENT_CHAR)
	{
		if (s[i] != '\t' && s[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	check_symbols_at_end_comment(t_asm *the_asm, char *s)
{
	int i;
	int start;
	int len;
	
	i = 0;
	len = 0;
	while (s[i] != '\0' && s[i] != '\"')
		i++;
	i++;
	start = i;
	while (s[i] != '\0' && s[i] != '\"')
	{
		i++;
		len++;
	}
	i++;
	while (s[i] != '\0' && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
	{
		if (s[i] != '\t' && s[i] != ' ')
			ERROR(SYMBOLS_COMMENT, the_asm->curr_line_n);
		i++;
	}
	the_asm->champion_comment = ft_strsub(s, start, len);
}

int		closing_quote_comment_is_valid(t_asm *the_asm, char *s)
{
	int kavichki;
	int met_hash;
	int i;

	i = 0;
	kavichki = 0;
	met_hash = 0;
	if (ft_strstr(s, NAME_CMD_STRIN))
		ERROR(NO_CLSNG_QT_COMMENT, the_asm->curr_line_n);
	while (s[i] != '\0')
	{
		if ((s[i] == COMMENT_CHAR || s[i] == ALT_COMMENT_CHAR) && kavichki == 1)
			met_hash = 1;
		if (s[i] == '\"' && met_hash == 0)
			kavichki++;
		i++;
	}
	if (kavichki > 1)
		ERROR(KAVICHKI_NUMBER, the_asm->curr_line_n);
	i = 0;
	while (s[i] != '\0' && s[i] != '\"')
		i++;
	i++;
	while (s[i] != '\0' && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
	{
		if (s[i] != '\t' && s[i] != ' ')
			ERROR(SYMBOLS_COMMENT, the_asm->curr_line_n);
		i++;
	}
	return (1);
}

int		search_closing_quote_comment(t_asm *the_asm, t_line **line)
{
	int i;

	i = 0;
	while ((*line)->str[i] != '\0' && (*line)->str[i] != '\"')
		i++;
	i++;
	the_asm->champion_comment = ft_strjoin(&(*line)->str[i], "\n");
	*line = (*line)->next;
	the_asm->curr_line_n++;
	while (*line)
	{
		the_asm->champion_comment = ft_strjoin(the_asm->champion_comment, (*line)->str);
		the_asm->champion_comment = ft_strjoin(the_asm->champion_comment, "\n");
		if (ft_strchr((*line)->str, '\"') &&
		closing_quote_comment_is_valid(the_asm, (*line)->str))
		{
			i = 0;
			while (the_asm->champion_comment[i] != '\0' && the_asm->champion_comment[i] != '\"')
				i++;
			the_asm->champion_comment = ft_strsub(the_asm->champion_comment, 0, i);
			return (1);
		}
		*line = (*line)->next;
		the_asm->curr_line_n++;
	}
	ERROR(NO_CLSNG_QT_COMMENT, the_asm->curr_line_n);
	return (0);
}

void	check_comment(t_asm *the_asm, t_line **line)
{
	int kavichki;//BE CAREFUL AND NOTE THAT YOU ARE POTENTIALLY ABOUT TO LOOSE POINTERS HERE!

	if (anything_after_dot_comment(the_asm, (*line)->str))
		ERROR(SYMBOLS_CMND_COMMENT, the_asm->curr_line_n);
	kavichki = count_kavichki((*line)->str);
	if (kavichki == 2)
		check_symbols_at_end_comment(the_asm, (*line)->str);
	if (kavichki > 2)
		ERROR(KAVICHKI_NUMBER, the_asm->curr_line_n);
	if (kavichki == 0)
		ERROR(NO_COMMENT, the_asm->curr_line_n);
	if (kavichki == 1)
		search_closing_quote_comment(the_asm, line);//RIGHT HERE I MEAN
	if (the_asm->champion_comment[0] == '\0')
	{
		printf("Empty champ comment.\n");
		exit(0);
	}
}