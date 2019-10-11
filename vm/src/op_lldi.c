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
	int32_t		val[2];
	t_mem		res;

	carriage->pos_tmp = (carriage->pos + 2) % MEM_SIZE;
	if (arg_read(data, carriage, data->mem_f[(carriage->pos + 1)
		% MEM_SIZE]))
	{
		get_val_ldi(*carriage, &val[0], 0);
		get_val_ldi(*carriage, &val[1], 1);
		adds = (carriage->pos + (val[0] + val[1])) % MEM_SIZE;
		ft_res_init(data, &res, adds);
		memory_cpy(&carriage->arg[2], res);
		carriage->carry = !(*(uint32_t*)carriage->arg[2].mem);
		if (data->verb_nbr & 4 && !data->vis)
		{
			ft_printf("P %4d | lldi %d %d r%d\n", carriage->nbr, val[0], val[1],
				get_num_reg(carriage, 2));
			ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
				val[0], val[1], val[0] + val[1],
				(int32_t)carriage->pos + (val[0] + val[1]));
		}
	}
	show_pc_movement(data, *carriage);
	carriage->pos = carriage->pos_tmp;
}
