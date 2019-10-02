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

void op_aff(t_general *data, t_carriage *carriage)
{
	char val;

	carriage->position_tmp = carriage->position + 2;
	if (arg_read(data, carriage, data->mem_f[carriage->position + 1]))
	{
		val = (char)get_val32bit(carriage->arg[0]);
		ft_printf("%c", val);
		carriage->carry = 0;
	}
	carriage->position = carriage->position_tmp;
}
