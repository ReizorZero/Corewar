/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:53:47 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 17:53:49 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		go_past_label(char *s, int i)
{
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != LABEL_CHAR)
		i++;
	i++;
	return (i);
}

int		go_past_command(t_asm *the_asm, char *s, int i)
{
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] != '\0' && s[i] != ' ' &&
	s[i] != '\t' && s[i] != SEPARATOR_CHAR)
		i++;
	if (s[i] == SEPARATOR_CHAR)
		ERROR(SEPARATOR_AFTER_CMND, the_asm->curr_line_n);
	return (i);
}

int		go_past_arg_1(t_asm *the_asm, char *s, int i, int words)
{
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] != '\0' && s[i] != ' ' &&
	s[i] != '\t' && s[i] != SEPARATOR_CHAR)
		i++;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] == SEPARATOR_CHAR &&
	(words == 2 + the_asm->e_c_l->first_is_label))
		ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
	if (s[i] != SEPARATOR_CHAR &&
	(words >= 3 + the_asm->e_c_l->first_is_label))
		ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
	if (s[i] == SEPARATOR_CHAR)
		i++;
	return (i);
}

int		go_past_arg_2(t_asm *the_asm, char *s, int i, int words)
{
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] != '\0' && s[i] != ' ' &&
	s[i] != '\t' && s[i] != SEPARATOR_CHAR)
		i++;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] == SEPARATOR_CHAR &&
	(words == 3 + the_asm->e_c_l->first_is_label))
		ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
	if (s[i] != SEPARATOR_CHAR &&
	(words == 4 + the_asm->e_c_l->first_is_label))
		ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
	if (s[i] == SEPARATOR_CHAR)
		i++;
	return (i);
}

int		go_past_arg_3(t_asm *the_asm, char *s, int i, int words)
{
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] != '\0' && s[i] != ' ' &&
	s[i] != '\t' && s[i] != SEPARATOR_CHAR)
		i++;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] == SEPARATOR_CHAR &&
	(words == 4 + the_asm->e_c_l->first_is_label))
		ERROR(WRONG_N_SEPARATORS, the_asm->curr_line_n);
	return (i);
}
