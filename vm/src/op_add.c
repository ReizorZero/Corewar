/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:18:42 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/01 15:18:44 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void	op_add(t_general *data, t_carriage *carriage)
{
	uint32_t val1;
	uint32_t val2;

	carriage->position_tmp = (carriage->position + 2) % MEM_SIZE;
	if (arg_read(data, carriage, data->mem_f[(carriage->position + 1)
		% MEM_SIZE]))
	{
		val1 = get_val32bit(carriage->arg[0]);
		val2 = get_val32bit(carriage->arg[1]);
		*(uint32_t*)carriage->arg[2].mem = reverse_32bits(val1 + val2);
		carriage->carry = !(*(uint32_t*)carriage->arg[2].mem);
		if (data->verb_nbr & 4)
		{
			ft_printf("P %4d | add r%d r%d r%d\n", carriage->nbr,
				get_num_reg(carriage, 0), get_num_reg(carriage, 1),
				get_num_reg(carriage, 2));
		}
	}
	show_pc_movement(*data, *carriage);
	carriage->position = carriage->position_tmp;
}
