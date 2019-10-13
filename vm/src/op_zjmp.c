/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:36:06 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/01 15:36:07 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

void	op_zjmp(t_general *data, t_carriage *crg)
{
	int16_t	dist;

	crg->pos_tmp = (crg->pos + 1) % MEM_SIZE;
	arg_read(data, crg, 0b10000000);
	dist = (int16_t)get_val16bit(crg->arg[0]);
	if (data->verb_nbr & 4 && !data->vis)
	{
		ft_printf("P %4d | zjmp %d %s\n", crg->nbr, dist,
			(crg->carry ? "OK" : "FAILED"));
	}
	if (crg->carry)
	{
		crg->pos_tmp = crg->pos;
		crg->pos = (crg->pos + dist % IDX_MOD) % MEM_SIZE;
	}
	else
	{
		crg->pos_tmp = crg->pos;
		crg->pos = (crg->pos + show_pc_movement(data, *crg)) % MEM_SIZE;
	}
}
