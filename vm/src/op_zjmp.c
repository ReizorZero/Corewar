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

void op_zjmp(t_general *data, t_carriage *carriage)
{
	short	dist;

	arg_read(data, carriage, 0b10000000);
	if (carriage->carry)
	{
		dist = get_val16bit(&carriage->arg[0]) % IDX_MOD;
		carriage->position = (carriage->position + dist) % MEM_SIZE;
	}
	carriage->carry = 0;
}
