/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live_carriage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:58:43 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/09 14:58:45 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

static void	carriage_live(t_carriage **crwl, t_carriage **prv_crwl)
{
	(*crwl)->live = 0;
	*prv_crwl = *crwl;
	*crwl = (*crwl)->next;
}

static void	message_kill(t_general *data, t_carriage crwl)
{
	if (data->verb_nbr & 8 && !data->vis)
	{
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
			crwl.nbr, ((data->cycles_total + data->cycles_tmp)
			- crwl.lst_live_cycle), data->cycles_to_die);
	}
	if (data->vis)
	{
		if (data->map_clr[crwl.pos_tmp].clr % 5)
			data->map_clr[crwl.pos_tmp].clr %= 5;
		else
			data->map_clr[crwl.pos_tmp].clr = 5;
		if (data->map_clr[crwl.pos].clr % 5)
			data->map_clr[crwl.pos].clr %= 5;
		else
			data->map_clr[crwl.pos].clr = 5;
	}
	data->num_died_carriege += 1;
}

void		ft_check_live_carriage(t_general *data)
{
	t_carriage	*crwl;
	t_carriage	*prv_crwl;

	crwl = data->head_c;
	prv_crwl = NULL;
	while (crwl)
	{
		if (crwl->live && (long int)crwl->lst_live_cycle > data->cycles_total
			&& data->cycles_to_die > 0)
			carriage_live(&crwl, &prv_crwl);
		else
		{
			if (!prv_crwl)
				data->head_c = crwl->next;
			else if (prv_crwl)
				prv_crwl->next = crwl->next;
			message_kill(data, *crwl);
			free(crwl);
			crwl = NULL;
			if (!prv_crwl)
				crwl = data->head_c;
			else
				crwl = prv_crwl->next;
		}
	}
}

void		start_new_op(t_general *data, t_carriage *crg)
{
	if (data->mem_f[crg->pos] > 0 && data->mem_f[crg->pos] <= 16)
	{
		crg->op_id = (uint8_t)data->mem_f[crg->pos];
		crg->op_cycles = (int)g_op_tab[crg->op_id - 1].cycles;
	}
	else
	{
		crg->pos_tmp = crg->pos;
		crg->pos = (crg->pos + 1) % MEM_SIZE;
	}
}

void		set_new_cycle(t_general *data)
{
	if (data->cnt_live >= NBR_LIVE || ++data->num_checks >= MAX_CHECKS)
	{
		data->cycles_to_die -= CYCLE_DELTA;
		if (data->verb_nbr & 2 && !data->vis)
			ft_printf("Cycle to die is now %d\n", data->cycles_to_die);
		data->num_checks = 0;
	}
	data->cycles_total += data->cycles_tmp;
	data->cnt_live = 0;
	data->cycles_tmp = 0;
}
