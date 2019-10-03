/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:18:18 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/01 15:18:20 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void op_st(t_general *data, t_carriage *carriage)
{
	carriage->position_tmp = carriage->position + 2;
	if (arg_read(data, carriage, data->mem_f[carriage->position + 1]))
	{
		memory_cpy(&carriage->arg[1], carriage->arg[0]);
		carriage->carry = 0;
		if (data->verb_nbr & 4) //verb_nbr 4
		{
			ft_printf("P %4d | st r%d %d\n", carriage->nbr,
					get_num_reg(*carriage, 0), get_val32bit(carriage->arg[1]));
		}
	}
	show_pc_movement(*data, *carriage);
	carriage->position = carriage->position_tmp;
}
