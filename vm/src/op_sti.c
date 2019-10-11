/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:50:31 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/01 16:50:32 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void	op_sti(t_general *data, t_carriage *carriage)
{
	uint32_t	adds;
	int32_t		val2;
	int32_t		val3;
	t_mem		res;

	carriage->pos_tmp = (carriage->pos + 2) % MEM_SIZE;
	if (arg_read(data, carriage, data->mem_f[(carriage->pos + 1)
		% MEM_SIZE]))
	{
		get_val_ldi(*carriage, &val2, 1);
		get_val_ldi(*carriage, &val3, 2);
		adds = (carriage->pos + (val2 + val3) % IDX_MOD) % MEM_SIZE;
		ft_res_init(data, &res, adds);
		memory_cpy(&res, carriage->arg[0]);
		if (data->verb_nbr & 4 && !data->vis)
		{
			ft_printf("P %4d | sti r%d %d %d\n", carriage->nbr,
				get_num_reg(carriage, 0), val2, val3);
			ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)"
				"\n", val2, val3, val2 + val3,
				(int32_t)(carriage->pos + (val2 + val3) % IDX_MOD));
		}
	}
	show_pc_movement(data, *carriage);
	carriage->pos = carriage->pos_tmp;
}
