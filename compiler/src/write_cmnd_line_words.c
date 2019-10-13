/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cmnd_line_words.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:44:36 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 13:44:38 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		operate_separator_char(char *s, int i, int *met_sep)
{
	if (s[i] == SEPARATOR_CHAR)
	{
		*met_sep = 1;
		i++;
	}
	return (i);
}

void	extract_word(t_asm *the_asm, char *s)
{
	the_asm->line_words[the_asm->curr_w_i] = ft_strsub(s,
	the_asm->curr_start, the_asm->curr_len);
	the_asm->curr_w_i++;
}

int		met_first_word(t_asm *the_asm, char *s, int i, int *met_label)
{
	i = operate_first_word(the_asm, s, i);
	i = operate_label_char(the_asm, s, i, met_label);
	return (i);
}

void	set_indices_values(t_asm *the_asm, int i)
{
	the_asm->curr_start = i;
	the_asm->curr_len = 0;
}

void	write_cmnd_line_words(t_asm *the_asm, t_line **line)
{
	char	*s;
	int		i;
	int		met_sep;
	int		met_label;

	s = (*line)->str;
	i = 0;
	the_asm->curr_w_i = 0;
	met_label = 0;
	while (the_asm->curr_w_i < MAX_WORDS_N)
	{
		if (the_asm->curr_w_i == 0)
			i = met_first_word(the_asm, s, i, &met_label);
		else
		{
			i = manage_separators(the_asm, s, i, met_label);
			met_sep = 0;
			set_indices_values(the_asm, i);
			i = manage_separators_again(the_asm, s, i);
			i = operate_separator_char(s, i, &met_sep);
			i = manage_separators_last(the_asm, s, i, met_sep);
		}
		extract_word(the_asm, s);
	}
	check_symbols_at_end(the_asm, s, i);
}
