/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_types_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:41:18 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 18:28:04 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	check_cmnd_correspondance(t_asm *the_asm, int arg_index)
{
	int i;
	int found_type;

	i = 0;
	found_type = 0;
	while (i < 3)
	{
		if (the_asm->e_c_l->arg_code[arg_index] ==
		g_commands[the_asm->e_c_l->cmnd_code - 1].arg_types[arg_index][i])
		{
			found_type = 1;
			break ;
		}
		i++;
	}
	if (!found_type)
		_ERROR(WRONG_ARG_TYPE, arg_index + 1, the_asm->curr_line_n);
}
