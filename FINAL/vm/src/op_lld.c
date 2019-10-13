/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:45:03 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/02 12:45:05 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void	op_lld(t_general *data, t_carriage *carriage)
{
	carriage->pos_tmp = (carriage->pos + 2) % MEM_SIZE;
	if (arg_read(data, carriage, data->mem_f[(carriage->pos + 1)
		% MEM_SIZE]))
	{
		memory_cpy(&carriage->arg[1], carriage->arg[0]);
		carriage->carry = !(*(uint32_t*)carriage->arg[0].mem);
		if (data->verb_nbr & 4 && !data->vis)
		{
			if (carriage->arg[1].type == T_IND)
			{
				ft_printf("P %4d | lld %d r%d\n", carriage->nbr,
					carriage->arg[0].ind_pntr, get_num_reg(carriage, 1));
			}
			else
			{
				ft_printf("P %4d | lld %d r%d\n", carriage->nbr,
					get_val32bit(carriage->arg[0]), get_num_reg(carriage, 1));
			}
		}
	}
	carriage->pos_tmp = carriage->pos;
	carriage->pos = (carriage->pos + show_pc_movement(data, *carriage)) % MEM_SIZE;
}
