/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:45:21 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/23 21:45:22 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void	op_and(t_general *data, t_carriage *carriage)
{
	uint32_t val1;
	uint32_t val2;

	carriage->pos_tmp = (carriage->pos + 2) % MEM_SIZE;
	if (arg_read(data, carriage, data->mem_f[(carriage->pos + 1)
		% MEM_SIZE]))
	{
		val1 = get_val32bit(carriage->arg[0]);
		val2 = get_val32bit(carriage->arg[1]);
		*(uint32_t*)carriage->arg[2].mem = reverse_32bits(val1 & val2);
		carriage->carry = !(*(uint32_t*)carriage->arg[2].mem);
		if (data->verb_nbr & 4 && !data->vis)
		{
			ft_printf("P %4d | and %d %d r%d\n", carriage->nbr, val1, val2,
				get_num_reg(carriage, 2));
		}
	}
	carriage->pos_tmp = carriage->pos;
	carriage->pos += show_pc_movement(data, *carriage);
}
