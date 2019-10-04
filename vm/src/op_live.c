/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:44:44 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/22 18:44:47 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void op_live(t_general *data, t_carriage *carriage)
{
	t_player *pl = NULL;
	uint32_t player;

	carriage->live = true;
	/*
	 * 0b10000000 - DIR in arg[0];
	 */
	carriage->position_tmp = carriage->position + 1;
	arg_read(data, carriage, 0b10000000);
	player = get_val32bit(carriage->arg[0]);
//	if (!(carriage->reg[0] + player))
	if ((pl = get_by_id(data, -player)))
	{
		data->lst_live_plr = player;
	}
	carriage->lst_live_cycle = data->cycles_total + data->cycles_tmp;
//	carriage->carry = 0;
	++(data->cnt_live);
	if (data->verb_nbr & 4) //verb_nbr 4
	{
		ft_printf("P %4d | live %d\n", carriage->nbr, player);
	}
	if (data->verb_nbr & 1) //verb_nbr 1
	{
		if (pl)
			ft_printf("Player %d (%s) is said to be alive\n", pl->id, pl->name);
	}
	show_pc_movement(*data, *carriage);
	carriage->position = carriage->position_tmp;
}
