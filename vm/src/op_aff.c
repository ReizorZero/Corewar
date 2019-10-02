/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:45:54 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/02 12:45:55 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void op_live(t_general *data, t_carriage *carriage)
{
	uint32_t player;

	carriage->live = true;
	/*
	 * 0b10000000 - DIR in arg[0];
	 */
	arg_read(data, carriage, 0b10000000);
	player = reverse_16bits(*(uint32_t *) carriage->arg[0].mem);
	if (!(carriage->reg[0] + player))
		data->lst_live_plr = player;
	carriage->lst_live_cycle = data->cycles_total + data->cycles_tmp;
	carriage->carry = 0;
	++(data->cnt_live);
}
