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

	carriage->position_tmp = carriage->position + 2;
	if (arg_read(data, carriage, data->mem_f[carriage->position + 1]))
	{
		if (carriage->arg[1].type == T_DIR)
			val2 = get_val16bit(carriage->arg[1]);
		else
			val2 = get_val32bit(carriage->arg[1]);
		if (carriage->arg[2].type == T_DIR)
			val3 = get_val16bit(carriage->arg[2]);
		else
			val3 = get_val32bit(carriage->arg[2]);
		adds = (carriage->position + (val2 + val3) % IDX_MOD) % MEM_SIZE;
		res.type = 0;
		res.mem = data->mem_f;
		res.current = &data->mem_f[adds];
		res.size = T_REG;
		res.mem_end = &data->mem_f[MEM_SIZE];
		memory_cpy(&res, carriage->arg[0]);
//		carriage->carry = 0;
		if (data->verb_nbr & 4) //verb_nbr 4
		{
			ft_printf("P %4d | sti r%d %d %d\n", carriage->nbr, get_num_reg(carriage, 0), val2, val3);
			ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n", val2, val3,
					  val2 + val3, adds);
		}
	}
	show_pc_movement(*data, *carriage);
	carriage->position = carriage->position_tmp;
}
