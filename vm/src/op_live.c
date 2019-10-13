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

#include "../../inc/corewar_vm.h"

static void	set_lst_cycle(t_general *data, uint8_t player)
{
	t_player *crwl;

	crwl = data->head_p;
	while (crwl)
	{
		if (player == crwl->id)
		{
			crwl->lst_cycle = data->cycles_total + data->cycles_tmp;
			return ;
		}
		crwl = crwl->next;
	}
}

void		op_live(t_general *data, t_carriage *crg)
{
	t_player *pl;
	uint32_t player;

	crg->live = true;
	pl = NULL;
	crg->pos_tmp = (crg->pos + 1) % MEM_SIZE;
	arg_read(data, crg, 0b10000000);
	player = get_val32bit(crg->arg[0]);
	if (-player == (uint8_t)(-player) && (pl = get_by_id(data, -player)))
	{
		data->lst_live_plr = -player;
		set_lst_cycle(data, -player);
		data->map_clr[crg->pos].cycle = 50;
		data->map_clr[crg->pos].clr = (data->map_clr[crg->pos].clr % 5) + 10;
	}
	crg->lst_live_cycle = data->cycles_total + data->cycles_tmp;
	++(data->cnt_live);
	if (data->verb_nbr & 4 && !data->vis)
		ft_printf("P %4d | live %d\n", crg->nbr, player);
	if (data->verb_nbr & 1 && !data->vis && pl)
		ft_printf("Player %d (%s) is said to be alive\n", pl->id, pl->name);
	crg->pos_tmp = crg->pos;
	crg->pos = (crg->pos + show_pc_movement(data, *crg)) % MEM_SIZE;
}
