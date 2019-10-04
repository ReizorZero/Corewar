/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:45:09 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/02 12:45:11 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void op_lldi(t_general *data, t_carriage *carriage)
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
		adds = (carriage->position + (val1 + val2)) % MEM_SIZE;
		res.type = 0;
		res.mem = data->mem_f;
		res.current = &data->mem_f[adds];
		res.size = T_REG;
		res.mem_end = &data->mem_f[MEM_SIZE];
		memory_cpy(&carriage->arg[2], res);
		carriage->carry = 0;
		if (data->verb_nbr & 4) //verb_nbr 4
		{
			ft_printf("P %4d | lldi %d %d r%d\n", carriage->nbr, val1, val2, get_num_reg(carriage, 2));
			ft_printf("       | -> load from %d + %d = %d (with pc %d)", val1, val2,
					  val1 + val2, carriage->position + (val1 + val2));
		}
	}
	show_pc_movement(*data, *carriage);
	carriage->position = carriage->position_tmp;
}
