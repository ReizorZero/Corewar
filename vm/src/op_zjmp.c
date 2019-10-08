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

#include "../inc/corewar_vm.h"

void	op_zjmp(t_general *data, t_carriage *carriage)
{
	int16_t	dist;

	carriage->position_tmp = (carriage->position + 1) % MEM_SIZE;
	arg_read(data, carriage, 0b10000000);
	dist = (int16_t)get_val16bit(carriage->arg[0]);
	if (data->verb_nbr & 4)
	{
		ft_printf("P %4d | zjmp %d %s\n", carriage->nbr, dist,
			(carriage->carry ? "OK" : "FAILED"));
	}
	if (carriage->carry)
		carriage->position = (carriage->position + dist % IDX_MOD) % MEM_SIZE;
	else
	{
		show_pc_movement(*data, *carriage);
		carriage->position = carriage->position_tmp;
	}
}
