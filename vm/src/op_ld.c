/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:45:55 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/27 18:45:58 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void op_ld(t_general *data, t_carriage *carriage)
{
	carriage->position_tmp = (carriage->position + 2) % MEM_SIZE;
	if (arg_read(data, carriage, data->mem_f[(carriage->position + 1) % MEM_SIZE]))
	{
		memory_cpy(&carriage->arg[1], carriage->arg[0]);
		carriage->carry = !(get_val32bit(carriage->arg[0]));
		if (data->verb_nbr & 4) //verb_nbr 4
		{
			if (carriage->arg[1].type == T_IND)
			{
				ft_printf("P %4d | ld %d r%d\n", carriage->nbr,
						  carriage->arg[0].IND_pntr, get_num_reg(carriage, 1));
			}
			else
			{
				ft_printf("P %4d | ld %d r%d\n", carriage->nbr,
						get_val32bit(carriage->arg[0]), get_num_reg(carriage, 1));
			}
		}
	}
	show_pc_movement(*data, *carriage);
	carriage->position = carriage->position_tmp;
}
