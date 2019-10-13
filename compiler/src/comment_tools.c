/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:48:29 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 17:48:31 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

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

void	check_comment_char_case(t_asm *the_asm, char *s)
{
	int i;

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
}
