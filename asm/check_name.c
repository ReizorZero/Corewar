/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:42:57 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 13:42:59 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_name_cmnd_tag(t_asm *the_asm, char *s, int i)
{
	int cmnd_len;
	
	cmnd_len = 5;
	if (s[i] != '.' ||
	s[i + 1] != 'n' ||
	s[i + 2] != 'a' ||
	s[i + 3] != 'm' ||
	s[i + 4] != 'e')
		ERROR(SYMBOLS_CMND_NAME, the_asm->curr_line_n);
	return (i + cmnd_len);
}

int		anything_after_dot_name(t_asm *the_asm, char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && (s[i] == '\t' || s[i] == ' '))
		i++;
	i = check_name_cmnd_tag(the_asm, s, i);
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

void	check_text_comment(char **s)
{
	int i;

	i = 0;
	if (s[0][0] == COMMENT_CHAR || s[0][0] == ALT_COMMENT_CHAR)
		*s = ft_strdup("");
	else if (ft_strchr(*s, COMMENT_CHAR) || (ft_strchr(*s, ALT_COMMENT_CHAR)))
	{
		while (s[0][i] != '\0' && s[0][i] != COMMENT_CHAR &&
		s[0][i] != ALT_COMMENT_CHAR)
			i++;
		*s = ft_strsub(*s, 0, (size_t)i);
	}
}

void	check_symbols_at_end_name(t_asm *the_asm, char *s)
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
			ERROR(SMBLS_CHAMP_NAME, the_asm->curr_line_n);
		i++;
	}
	the_asm->champion_name = ft_strsub(s, start, len);
}

void	check_comment_char_case_name(t_asm *the_asm, char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\"')
		i++;
	i++;
	while (s[i] != '\0' && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
	{
		if (s[i] != '\t' && s[i] != ' ')
			ERROR(SMBLS_CHAMP_NAME, the_asm->curr_line_n);
		i++;
	}
}

int		closing_quote_name_is_valid(t_asm *the_asm, char *s)
{
	int kavichki;
	int met_hash;
	int i;

	i = 0;
	kavichki = 0;
	met_hash = 0;
	if (ft_strstr(s, COMMENT_CMD_STRING))
		ERROR(CLSNG_QT_CHAMP_NAME, the_asm->curr_line_n);
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
	check_comment_char_case_name(the_asm, s);
	return (1);
}

int		found_closing_quote_name(t_asm *the_asm)
{
	int i;

	i = 0;
	while (the_asm->champion_name[i] != '\0' &&
	the_asm->champion_name[i] != '\"')
		i++;
	the_asm->champion_name = ft_strsub(the_asm->champion_name, 0, i);
		return (1);
}

int		search_closing_quote_name(t_asm *the_asm, t_line **line)
{
	int i;

	i = 0;
	while ((*line)->str[i] != '\0' && (*line)->str[i] != '\"')
		i++;
	i++;
	the_asm->champion_name = ft_strjoin(&(*line)->str[i], "\n");
	add_garbage(the_asm, the_asm->champion_name);
	*line = (*line)->next;
	the_asm->curr_line_n++;
	while (*line)
	{
		the_asm->champion_name = ft_strjoin(the_asm->champion_name,
		(*line)->str);
		add_garbage(the_asm, the_asm->champion_name);
		the_asm->champion_name = ft_strjoin(the_asm->champion_name, "\n");
		add_garbage(the_asm, the_asm->champion_name);
		if (ft_strchr((*line)->str, '\"') &&
		closing_quote_name_is_valid(the_asm, (*line)->str))
			found_closing_quote_name(the_asm);
		*line = (*line)->next;
		the_asm->curr_line_n++;
	}
	ERROR(CLSNG_QT_CHAMP_NAME, the_asm->curr_line_n);
	return (0);
}

void	check_name(t_asm *the_asm, t_line **line)
{
	int kavichki;

	if (anything_after_dot_name(the_asm, (*line)->str))
		ERROR(SYMBOLS_CMND_NAME, the_asm->curr_line_n);
	kavichki = count_kavichki((*line)->str);
	if (kavichki == 2)
		check_symbols_at_end_name(the_asm, (*line)->str);
	if (kavichki > 2)
		ERROR(KAVICHKI_NUMBER, the_asm->curr_line_n);
	if (kavichki == 0)
		ERROR(NO_CHAMP_NAME, the_asm->curr_line_n);
	if (kavichki == 1)
		search_closing_quote_name(the_asm, line);
	if (the_asm->champion_name[0] == '\0')
		ERROR(EMPTY_CHAMP_NAME, the_asm->curr_line_n);
}
