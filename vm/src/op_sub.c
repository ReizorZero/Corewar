/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:18:25 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/01 15:18:26 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void op_sub(t_general *data, t_carriage *carriage)
{
	uint32_t val1;
	uint32_t val2;

	carriage->position = +1;
	if (arg_read(data, carriage, data->mem_f[carriage->position]))
	{
		val1 = get_val32bit(&carriage->arg[0]);
		val2 = get_val32bit(&carriage->arg[1]);
		*(uint32_t*)carriage->arg[2].mem = val1 - val2;
		carriage->carry = !(*(uint32_t*)carriage->arg[2].mem);
	}
}