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
	carriage->live = true;
//	carriage->position += 1;
	/*
	 * 0b10000000 - DIR in arg[0];
	 */
	arg_read(data, carriage, 0b10000000);
	if (!(carriage->reg[0] + (int32_t)carriage->arg[0].mem))
		data->lst_live_plr = (int8_t)carriage->arg[0].mem;
	carriage->lst_live_cycle = data->cycles_tmp + data->cycles_total;
	++(data->cnt_live);
}