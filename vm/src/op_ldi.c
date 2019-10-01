/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:50:19 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/01 16:50:21 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void op_ldi(t_general *data, t_carriage *carriage)
{
	size_t	adds;
	int32_t val1;
	int32_t val2;

	carriage->position = +1;
	if (arg_read(data, carriage, data->mem_f[carriage->position]))
	{
		if (carriage->arg[0].type == T_DIR)
			val1 = get_val16bit(&carriage->arg[0]);
		else
			val1 = get_val32bit(&carriage->arg[0]);
		if (carriage->arg[1].type == T_DIR)
			val2 = get_val16bit(&carriage->arg[1]);
		else
			val2 = get_val32bit(&carriage->arg[1]);
		adds = (carriage->position + (val1 + val2) % IDX_MOD) % MEM_SIZE;
//		memory_cpy(&carriage->arg[1], &carriage->arg[0]);
//		carriage->carry = !(*(uint32_t*)carriage->arg[0].mem);
	}
}

