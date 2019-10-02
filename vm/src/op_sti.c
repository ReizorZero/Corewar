/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:50:31 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/01 16:50:32 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void op_sti(t_general *data, t_carriage *carriage)
{
	size_t	adds;
	int32_t val2;
	int32_t val3;
	t_mem	res;

	carriage->position += 1;
	if (arg_read(data, carriage, data->mem_f[carriage->position]))
	{
		if (carriage->arg[1].type == T_DIR)
			val2 = get_val16bit(&carriage->arg[1]);
		else
			val2 = get_val32bit(&carriage->arg[1]);
		if (carriage->arg[2].type == T_DIR)
			val3 = get_val16bit(&carriage->arg[2]);
		else
			val3 = get_val32bit(&carriage->arg[2]);
		adds = (carriage->position + (val2 + val3) % IDX_MOD) % MEM_SIZE;
		res.type = 0;
		res.mem = data->mem_f;
		res.current = &data->mem_f[adds];
		res.size = T_REG;
		res.mem_end = &data->mem_f[MEM_SIZE];
		memory_cpy(&res, &carriage->arg[0]);
		carriage->carry = 0;
	}
}
