/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:45:03 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/02 12:45:05 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

void	op_lld(t_general *data, t_carriage *crg)
{
	crg->pos_tmp = (crg->pos + 2) % MEM_SIZE;
	if (arg_read(data, crg, data->mem_f[(crg->pos + 1) % MEM_SIZE]))
	{
		memory_cpy(&crg->arg[1], crg->arg[0]);
		crg->carry = !(*(uint32_t*)crg->arg[0].mem);
		if (data->verb_nbr & 4 && !data->vis)
		{
			if (crg->arg[1].type == T_IND)
			{
				ft_printf("P %4d | lld %d r%d\n", crg->nbr,
					crg->arg[0].ind_pntr, get_num_reg(crg, 1));
			}
			else
			{
				ft_printf("P %4d | lld %d r%d\n", crg->nbr,
					get_val32bit(crg->arg[0]), get_num_reg(crg, 1));
			}
		}
	}
	crg->pos_tmp = crg->pos;
	crg->pos = (crg->pos + show_pc_movement(data, *crg)) % MEM_SIZE;
}
