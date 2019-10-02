/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:45:03 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/02 12:45:05 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void op_lld(t_general *data, t_carriage *carriage)
{
	carriage->position_tmp = carriage->position + 2;
	if (arg_read(data, carriage, data->mem_f[carriage->position + 1]))
	{
		memory_cpy(&carriage->arg[1], &carriage->arg[0]);
		carriage->carry = !(*(uint32_t*)carriage->arg[0].mem);
	}
	carriage->position = carriage->position_tmp;
}
