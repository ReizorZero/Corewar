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

#include "../../inc/corewar_vm.h"

void	op_lldi(t_general *data, t_carriage *crg)
{
	uint32_t	adds;
	int32_t		val[2];
	t_mem		res;

	crg->pos_tmp = (crg->pos + 2) % MEM_SIZE;
	if (arg_read(data, crg, data->mem_f[(crg->pos + 1) % MEM_SIZE]))
	{
		get_val_ldi(*crg, &val[0], 0);
		get_val_ldi(*crg, &val[1], 1);
		adds = (crg->pos + (val[0] + val[1])) % MEM_SIZE;
		ft_res_init(data, &res, adds);
		memory_cpy(&crg->arg[2], res);
		crg->carry = !(*(uint32_t*)crg->arg[2].mem);
		if (data->verb_nbr & 4 && !data->vis)
		{
			ft_printf("P %4d | lldi %d %d r%d\n", crg->nbr, val[0], val[1],
				get_num_reg(crg, 2));
			ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
				val[0], val[1], val[0] + val[1],
				(int32_t)crg->pos + (val[0] + val[1]));
		}
	}
	crg->pos_tmp = crg->pos;
	crg->pos = (crg->pos + show_pc_movement(data, *crg)) % MEM_SIZE;
}
