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

#include "../../inc/corewar_vm.h"

void	op_add(t_general *data, t_carriage *crg)
{
	uint32_t val1;
	uint32_t val2;

	crg->pos_tmp = (crg->pos + 2) % MEM_SIZE;
	if (arg_read(data, crg, data->mem_f[(crg->pos + 1) % MEM_SIZE]))
	{
		val1 = get_val32bit(crg->arg[0]);
		val2 = get_val32bit(crg->arg[1]);
		*(uint32_t*)crg->arg[2].mem = reverse_32bits(val1 + val2);
		crg->carry = !(*(uint32_t*)crg->arg[2].mem);
		if (data->verb_nbr & 4 && !data->vis)
		{
			ft_printf("P %4d | add r%d r%d r%d\n", crg->nbr,
				get_num_reg(crg, 0), get_num_reg(crg, 1),
				get_num_reg(crg, 2));
		}
	}
	crg->pos_tmp = crg->pos;
	crg->pos = (crg->pos + show_pc_movement(data, *crg)) % MEM_SIZE;
}
