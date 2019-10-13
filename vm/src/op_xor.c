/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:47:58 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/01 13:48:05 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

void	op_xor(t_general *data, t_carriage *crg)
{
	uint32_t val1;
	uint32_t val2;

	crg->pos_tmp = (crg->pos + 2) % MEM_SIZE;
	if (arg_read(data, crg, data->mem_f[(crg->pos + 1) % MEM_SIZE]))
	{
		val1 = get_val32bit(crg->arg[0]);
		val2 = get_val32bit(crg->arg[1]);
		*(uint32_t*)crg->arg[2].mem = reverse_32bits(val1 ^ val2);
		crg->carry = !(*(uint32_t*)crg->arg[2].mem);
		if (data->verb_nbr & 4 && !data->vis)
		{
			ft_printf("P %4d | xor %d %d r%d\n", crg->nbr, val1, val2,
				get_num_reg(crg, 2));
		}
	}
	crg->pos_tmp = crg->pos;
	crg->pos = (crg->pos + show_pc_movement(data, *crg)) % MEM_SIZE;
}
