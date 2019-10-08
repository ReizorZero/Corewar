/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:45:09 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/02 12:45:11 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void	op_lldi(t_general *data, t_carriage *carriage)
{
	uint32_t	adds;
	int32_t		val1;
	int32_t		val2;
	t_mem		res;

	carriage->position_tmp = (carriage->position + 2) % MEM_SIZE;
	if (arg_read(data, carriage, data->mem_f[(carriage->position + 1)
		% MEM_SIZE]))
	{
		get_val_ldi(*carriage, &val1, 0);
		get_val_ldi(*carriage, &val2, 1);
		adds = (carriage->position + (val1 + val2)) % MEM_SIZE;
		ft_res_init(data, &res, adds);
		memory_cpy(&carriage->arg[2], res);
		if (data->verb_nbr & 4)
		{
			ft_printf("P %4d | lldi %d %d r%d\n", carriage->nbr, val1, val2,
				get_num_reg(carriage, 2));
			ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
				val1, val2, val1 + val2,
				(int32_t)carriage->position + (val1 + val2));
		}
	}
	show_pc_movement(*data, *carriage);
	carriage->position = carriage->position_tmp;
}
