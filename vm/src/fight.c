/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:38:13 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/24 20:38:14 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void	ft_check_live_carriage(t_general *data)
{
	t_carriage	*crwl;
	t_carriage	*prv_crwl;

	crwl = data->head_c;
	if (!crwl->live)
	{
		data->head_c = crwl->next;
		free(crwl);
		crwl = data->head_c->next;
	}
	prv_crwl = data->head_c;
	while (crwl)
	{
		if (!crwl->live)
		{
			prv_crwl->next = crwl->next;
			free(crwl);
			crwl = prv_crwl->next;
		}
		else
		{
			crwl->live = 0;
			prv_crwl = crwl;
			crwl = crwl->next;
		}
	}
}

void start_new_op(t_general *data, t_carriage *crg)
{
	if (data->mem_f[crg->position] > 0 && data->mem_f[crg->position] <= 16)
	{
		crg->op_id = (uint8_t)data->mem_f[crg->position];
		crg->op_cycles = (int)op_tab[crg->op_id - 1].cycles;
	}
	else
	{
		/*
		 * В этом случае необходимо запомнить считанный код, а значение
		 * переменной, хранящей количество циклов до выполнения, оставить
		 * равным нулю.
		 */
		crg->position += 1;
	}
}

void	set_new_cycle(t_general *data)
{
	if (data->cnt_live >= NBR_LIVE || ++data->num_checks >= MAX_CHECKS)
	{
		data->cycles_to_die -= CYCLE_DELTA;
		data->num_checks = 0;
	}
	data->cnt_live = 0;
	data->cycles = 1;
}

void	ft_fight(t_general *data)
{
	t_carriage	*crwl = NULL;

	data->cycles_to_die = CYCLE_TO_DIE;
	data->cycles = 1;
	while (data->head_c)
	{
		crwl = data->head_c;
		while (crwl && data->cnt_live < NBR_LIVE)
		{
			if (crwl->op_cycles < 0)
				start_new_op(data, crwl);
			if (crwl->op_cycles > 0)
				--(crwl->op_cycles);
			if (!crwl->op_cycles)
			{
				if (arg_read(data, crwl))
					op_func[crwl->op_id - 1](data, crwl);
			}
			crwl = crwl->next;
		}
		if (data->cycles++ >= data->cycles_to_die)
		{
			ft_check_live_carriage(data);
			set_new_cycle(data);
		}
	}
}
