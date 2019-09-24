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

}

void	start_new_op(t_general *data, t_carriage *crg)
{
	if (data->mem_f[crg->position] > 0 && data->mem_f[crg->position] <= 16)
	{
		crg->op_id = data->mem_f[crg->position];
		crg->op_cycles = op_tab[crg->op_id - 1].cycles;
	}
	else
		crg->position += 1;
}

void	ft_fight(t_general *data)
{
	t_carriage	*crwl;

	while (data->head_c)
	{
		data->cycles_to_die = CYCLE_TO_DIE;
		crwl = data->head_c;
		while (crwl && data->cnt_live < NBR_LIVE)
		{
			if (crwl->op_cycles < 0)
				start_new_op(data, crwl);
			else if (!crwl->op_cycles)
				op_func[crwl->op_id](data, crwl);
			else if (crwl->op_cycles > 0)
				--crwl->op_cycles;
			crwl = crwl->next;
		}
		if (!(--data->cycles_to_die))
			ft_check_live_carriage(data);
		else
	}
}
