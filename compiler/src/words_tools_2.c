/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:55:57 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 17:55:59 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	check_separators(t_asm *the_asm, t_line **line)
{
	char	*s;
	int		i;
	int		words;

	i = 0;
	s = (*line)->str;
	words = the_asm->e_c_l->words;
	if (the_asm->e_c_l->first_is_label)
		i = go_past_label(s, i);
	i = go_past_command(the_asm, s, i);
	i = go_past_arg_1(the_asm, s, i, words);
	i = go_past_arg_2(the_asm, s, i, words);
	i = go_past_arg_3(the_asm, s, i, words);
}
