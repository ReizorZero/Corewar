/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:50:39 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/01 16:50:40 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

void	op_fork(t_general *data, t_carriage *crg)
{
	int16_t		adds;
	t_carriage	*new;

	crg->pos_tmp = (crg->pos + 1) % MEM_SIZE;
	arg_read(data, crg, 0b10000000);
	adds = (int16_t)get_val16bit(crg->arg[0]);
	if (!(new = ft_new_carriage(0, 0)))
	{
		ft_printf("Error: can't create new carriage!\n");
		ft_mem_clean(data);
		exit(1);
	}
	ft_memmove(new, crg, sizeof(t_carriage));
	new->pos = (crg->pos + adds % IDX_MOD) % MEM_SIZE;
	new->nbr = ++data->num_carriage;
	new->op_cycles = -1;
	new->next = data->head_c;
	data->head_c = new;
	if (data->verb_nbr & 4 && !data->vis)
	{
		ft_printf("P %4d | fork %d (%d)\n", crg->nbr, adds,
			(int32_t)(crg->pos + adds % IDX_MOD));
	}
	crg->pos_tmp = crg->pos;
	crg->pos = (crg->pos + show_pc_movement(data, *crg)) % MEM_SIZE;
}
