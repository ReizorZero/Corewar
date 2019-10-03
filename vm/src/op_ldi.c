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
	t_mem	res;

	carriage->position_tmp = carriage->position + 2;
	if (arg_read(data, carriage, data->mem_f[carriage->position + 1]))
	{
		if (carriage->arg[0].type == T_DIR)
			val1 = get_val16bit(carriage->arg[0]);
		else
			val1 = get_val32bit(carriage->arg[0]);
		if (carriage->arg[1].type == T_DIR)
			val2 = get_val16bit(carriage->arg[1]);
		else
			val2 = get_val32bit(carriage->arg[1]);
		adds = (carriage->position + (val1 + val2) % IDX_MOD) % MEM_SIZE;
		res.type = 0;
		res.mem = data->mem_f;
		res.current = &data->mem_f[adds];
		res.size = T_REG;
		res.mem_end = &data->mem_f[MEM_SIZE];
		memory_cpy(&carriage->arg[2], res);
		carriage->carry = 0;
	}
	carriage->position = carriage->position_tmp;
	if () //verb_nbr 4
	{
		//ft_printf("P %4d | ldi %d %d r%d\n", carriage_nbr, val1, val2, reg_number);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)", val1, val2,
			val1 + val2, (carriage->position + ((val1 + val2) % IDX_MOD)));
	}
}
