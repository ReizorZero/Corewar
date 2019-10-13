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

#include "../../inc/corewar_vm.h"

void	op_sti(t_general *data, t_carriage *crg)
{
	uint32_t	adds;
	int32_t		val2;
	int32_t		val3;
	t_mem		res;

	crg->pos_tmp = (crg->pos + 2) % MEM_SIZE;
	if (arg_read(data, crg, data->mem_f[(crg->pos + 1) % MEM_SIZE]))
	{
		get_val_ldi(*crg, &val2, 1);
		get_val_ldi(*crg, &val3, 2);
		adds = (crg->pos + (val2 + val3) % IDX_MOD) % MEM_SIZE;
		ft_res_init(data, &res, adds);
		memory_cpy(&res, crg->arg[0]);
		ft_set_color(data, res.size, res.current - res.mem, crg->pl_id + 5);
		if (data->verb_nbr & 4 && !data->vis)
		{
			ft_printf("P %4d | sti r%d %d %d\n", crg->nbr,
				get_num_reg(crg, 0), val2, val3);
			ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)"
				"\n", val2, val3, val2 + val3,
				(int32_t)(crg->pos + (val2 + val3) % IDX_MOD));
		}
	}
	crg->pos_tmp = crg->pos;
	crg->pos = (crg->pos + show_pc_movement(data, *crg)) % MEM_SIZE;
}
