/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:47:47 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/01 13:47:49 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void op_or(t_general *data, t_carriage *carriage)
{
	uint32_t val1;
	uint32_t val2;

	carriage->position_tmp = carriage->position + 2;
	if (arg_read(data, carriage, data->mem_f[carriage->position + 1]))
	{
		val1 = get_val32bit(carriage->arg[0]);
		val2 = get_val32bit(carriage->arg[1]);
		*(uint32_t*)carriage->arg[2].mem = val1 | val2;
		carriage->carry = !(*(uint32_t*)carriage->arg[2].mem);
		if (data->verb_nbr & 4) //verb_nbr 4
		{
			ft_printf("P %4d | or %d %d r%d\n", carriage->nbr, val1, val2,
					  get_num_reg(*carriage, 2));
		}
	}
	show_pc_movement(*data, *carriage);
	carriage->position = carriage->position_tmp;
}
