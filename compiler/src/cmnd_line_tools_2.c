/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmnd_line_tools_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:10:55 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 18:10:57 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		operate_label_char(t_asm *the_asm, char *s, int i, int *met_label)
{
	if (s[i] == LABEL_CHAR)
	{
		*met_label = 1;
		the_asm->e_c_l->first_is_label = 1;
		the_asm->curr_len++;
		i++;
	}
	return (i);
}
