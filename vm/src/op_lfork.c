/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:45:45 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/02 12:45:47 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void op_lfork(t_general *data, t_carriage *carriage)
{
	short	adds;

	carriage->carry = 0;
	/*
	 * 0b10000000 - DIR in arg[0];
	 */
	carriage->position_tmp = carriage->position + 1;
	arg_read(data, carriage, 0b10000000);
	adds = get_val32bit(carriage->arg[0]);
	if (!ft_add_carriage(&data->head_c, 0, ++data->num_carriage))
	{
		ft_printf("Error: can't create new carriage! PC = %i\n",
				  data->cycles_total + data->cycles_tmp);
	}
	ft_memmove(data->head_c, carriage, sizeof(t_carriage));
	data->head_c->position = (carriage->position + adds) % MEM_SIZE;
	show_pc_movement(*data, *carriage);
	carriage->position = carriage->position_tmp;
	if (data->verb_nbr & 4) //verb_nbr 4
	{
		ft_printf("P %4d | lfork %d (%d)\n", carriage->nbr, adds,
			(carriage->position + adds));
	}
}
