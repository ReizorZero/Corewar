/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:18:18 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/01 15:18:20 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

void	op_st(t_general *data, t_carriage *crg)
{
	crg->pos_tmp = (crg->pos + 2) % MEM_SIZE;
	if (arg_read(data, crg, data->mem_f[(crg->pos + 1) % MEM_SIZE]))
	{
		memory_cpy(&crg->arg[1], crg->arg[0]);
		if (crg->arg[1].type == T_IND)
			ft_set_color(data, crg->arg[1].size,
				crg->arg[1].current - crg->arg[1].mem,
				crg->pl_id + 5);
		if (data->verb_nbr & 4 && !data->vis)
		{
			if (crg->arg[1].type == T_IND)
			{
				ft_printf("P %4d | st r%d %d\n", crg->nbr,
					get_num_reg(crg, 0), crg->arg[1].ind_pntr);
			}
			else
			{
				ft_printf("P %4d | st r%d %d\n", crg->nbr,
					get_num_reg(crg, 0), get_num_reg(crg, 1));
			}
		}
	}
	crg->pos_tmp = crg->pos;
	crg->pos = (crg->pos + show_pc_movement(data, *crg)) % MEM_SIZE;
}
