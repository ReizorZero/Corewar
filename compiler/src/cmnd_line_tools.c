/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmnd_line_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:09:08 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 18:09:11 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		manage_separators(t_asm *the_asm, char *s, int i, int met_label)
{
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t') &&
	s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR &&
	s[i] != SEPARATOR_CHAR)
		i++;
	if (s[i] == SEPARATOR_CHAR && met_label && the_asm->curr_w_i == 1)
		ERROR(SEPARATOR_AFTER_LABEL, the_asm->curr_line_n);
	if (s[i] == SEPARATOR_CHAR && !met_label && the_asm->curr_w_i == 1)
		ERROR(SEPARATOR_AFTER_CMND, the_asm->curr_line_n);
	if (s[i] == SEPARATOR_CHAR && met_label && the_asm->curr_w_i == 2)
		ERROR(SEPARATOR_AFTER_CMND, the_asm->curr_line_n);
	return (i);
}

void	check_symbols_at_end(t_asm *the_asm, char *s, int i)
{
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] != '\0' && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
		ERROR(WRONG_SMBLS_AT_END, the_asm->curr_line_n);
}

int		operate_first_word(t_asm *the_asm, char *s, int i)
{
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t') &&
	s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
		i++;
	the_asm->curr_start = i;
	the_asm->curr_len = 0;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' &&
	s[i] != LABEL_CHAR && s[i] != COMMENT_CHAR &&
	s[i] != ALT_COMMENT_CHAR)
	{
		the_asm->curr_len++;
		i++;
	}
	return (i);
}

int		manage_separators_again(t_asm *the_asm, char *s, int i)
{
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' &&
	s[i] != SEPARATOR_CHAR && s[i] != COMMENT_CHAR &&
	s[i] != ALT_COMMENT_CHAR)
	{
		the_asm->curr_len++;
		i++;
	}
	return (i);
}

int		manage_separators_last(t_asm *the_asm, char *s, int i, int met_sep)
{
	if (s[i] == SEPARATOR_CHAR)
		ERROR(MANY_SEPARATORS, the_asm->curr_line_n);
	if (the_asm->curr_len == 0 && met_sep == 1)
	{
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t') &&
		s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
			i++;
		the_asm->curr_start = i;
		the_asm->curr_len = 0;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' &&
		s[i] != SEPARATOR_CHAR && s[i] != COMMENT_CHAR &&
		s[i] != ALT_COMMENT_CHAR)
		{
			the_asm->curr_len++;
			i++;
		}
		if (s[i] == SEPARATOR_CHAR)
			i++;
		if (s[i] == SEPARATOR_CHAR)
			ERROR(MANY_SEPARATORS, the_asm->curr_line_n);
	}
	return (i);
}
