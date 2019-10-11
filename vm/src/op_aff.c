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

void	op_aff(t_general *data, t_carriage *carriage)
{
	char val;

	carriage->pos_tmp = (carriage->pos + 2) % MEM_SIZE;
	if (arg_read(data, carriage, data->mem_f[(carriage->pos + 1)
		% MEM_SIZE]))
	{
		val = (char)get_val32bit(carriage->arg[0]);
		if (!data->vis)
			ft_printf("Aff: %c\n", val);
	}
	show_pc_movement(data, *carriage);
	carriage->pos = carriage->pos_tmp;
}
