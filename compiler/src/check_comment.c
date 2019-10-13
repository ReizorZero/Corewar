/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:33:10 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 17:45:34 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

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
		if ((s[i] == COMMENT_CHAR ||
		s[i] == ALT_COMMENT_CHAR) &&
		(kavichki >= 2 || kavichki == 0))
			met_hash = 1;
		if (s[i] == '\"' && met_hash == 0)
			kavichki++;
		i++;
	}
	return (kavichki);
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
	check_comment_char_case(the_asm, s);
	return (1);
}

int		found_closing_quote_comment(t_asm *the_asm)
{
	int i;

	i = 0;
	while (the_asm->champion_comment[i] != '\0' &&
	the_asm->champion_comment[i] != '\"')
		i++;
	the_asm->champion_comment = ft_strsub(the_asm->champion_comment,
	0, i);
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
	add_garbage(the_asm, the_asm->champion_comment);
	*line = (*line)->next;
	the_asm->curr_line_n++;
	while (*line)
	{
		the_asm->champion_comment = ft_strjoin(the_asm->champion_comment,
		(*line)->str);
		add_garbage(the_asm, the_asm->champion_comment);
		the_asm->champion_comment = ft_strjoin(the_asm->champion_comment, "\n");
		add_garbage(the_asm, the_asm->champion_comment);
		if (ft_strchr((*line)->str, '\"') &&
		closing_quote_comment_is_valid(the_asm, (*line)->str))
			return (found_closing_quote_comment(the_asm));
		*line = (*line)->next;
		the_asm->curr_line_n++;
	}
	ERROR(NO_CLSNG_QT_COMMENT, the_asm->curr_line_n);
	return (0);
}

void	check_comment(t_asm *the_asm, t_line **line)
{
	int kavichki;

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
		search_closing_quote_comment(the_asm, line);
	if (the_asm->champion_comment[0] == '\0')
		ERROR(EMPTY_COMMENT, the_asm->curr_line_n);
}
