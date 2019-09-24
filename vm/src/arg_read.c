/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:13:58 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/24 13:14:00 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void	read_dir(t_general *data, t_mem *arg, size_t position, size_t size)
{
	/*
	 * pointer to cell in field
	 */
	arg->mem = &data->mem_f[position];
	arg->total_s = size;
	arg->current = 0;
}

void	read_reg(t_general *data, t_carriage *carriage, t_mem *arg, size_t position)
{
	/*
	 * register pointer
	 */
	arg->mem = &carriage->reg[(unsigned char)data->mem_f[position] + 1];
	arg->total_s = REG_SIZE;
	arg->current = 0;
}

void	read_ind(t_general *data, t_mem *arg, size_t position)
{
	/*
	 * pointer to the cell to which the address points
	 */
	arg->mem = &data->mem_f[(short)data->mem_f[position]];
	arg->total_s = REG_SIZE;
	arg->current = 0;
}

void arg_read(t_general *data, t_carriage *carriage)
{
	int i;
	size_t tmp_position;

	i = 3;
	ft_memset(carriage->arg, 0, sizeof(carriage->arg));
	if (op_tab[carriage->op_id - 1].octal)
	{
		carriage->position += 1;
		tmp_position = carriage->position + 1;
		while (i > 0)
		{
			if (data->mem_f[carriage->position] >> (2 * i) & DIR_CODE)
			{
				read_dir(data, &carriage->arg[3 - i], tmp_position, DIR_SIZE - 2 * op_tab[carriage->op_id - 1].label);
				tmp_position = (tmp_position + DIR_SIZE - 2 * op_tab[carriage->op_id - 1].label) % MEM_SIZE;
			}
			else if (data->mem_f[carriage->position] >> (2 * i) & REG_CODE)
			{
				read_reg(data, carriage, &carriage->arg[3 - i], tmp_position);
				tmp_position = (tmp_position + 1) % MEM_SIZE;
			}
			else if (data->mem_f[carriage->position] >> (2 * i) & IND_CODE)
			{
				read_ind(data, &carriage->arg[3 - i], tmp_position);
				tmp_position = (tmp_position + IND_SIZE) % MEM_SIZE;
			}
			--i;
		}
		carriage->position = tmp_position;
	}

}
