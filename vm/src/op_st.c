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

#include "../inc/corewar_vm.h"

void	op_st(t_general *data, t_carriage *carriage)
{
	carriage->pos_tmp = (carriage->pos + 2) % MEM_SIZE;
	if (arg_read(data, carriage, data->mem_f[(carriage->pos + 1)
		% MEM_SIZE]))
	{
		memory_cpy(&carriage->arg[1], carriage->arg[0]);
		if (data->verb_nbr & 4 && !data->vis)
		{
			if (carriage->arg[1].type == T_IND)
			{
				ft_printf("P %4d | st r%d %d\n", carriage->nbr,
					get_num_reg(carriage, 0), carriage->arg[1].ind_pntr);
			}
			else
			{
				ft_printf("P %4d | st r%d %d\n", carriage->nbr,
					get_num_reg(carriage, 0), get_num_reg(carriage, 1));
			}
		}
	}
	show_pc_movement(data, *carriage);
	carriage->pos = carriage->pos_tmp;
}
