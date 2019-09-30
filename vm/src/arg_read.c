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
	arg->total_s = size + 1;
	arg->current = arg->mem;
	arg->type = T_DIR;
}

void	read_reg(t_general *data, t_carriage *carriage, t_mem *arg, size_t position)
{
	/*
	 * register pointer
	 */
	arg->mem = &carriage->reg[(unsigned char)data->mem_f[position] - 1];
//	arg->mem = &carriage->reg[(unsigned char)data->mem_f[position] + 1];
	arg->total_s = REG_SIZE + 1;
	arg->current = arg->mem;
	if (data->mem_f[position] > 0 && (unsigned char)data->mem_f[position] <= REG_NUMBER)
		arg->type = T_REG;
	else
		arg->type = 16;
		/*
		 * тип, который выдаст в valid_arg - false
		 */
}

void	read_ind(t_general *data, size_t crg_position, t_mem *arg, size_t position)
{
	/*
	 * pointer to the cell to which the address points
	 */
	size_t adds;

	adds = (crg_position + ((short)data->mem_f[position] % IDX_MOD)) % MEM_SIZE;
	arg->mem = &data->mem_f[adds];
	arg->total_s = REG_SIZE + 1;
	arg->current = arg->mem;
	arg->type = T_IND;
}

bool	valid_arg(t_mem *arg, uint8_t op_id)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (!(op_tab[op_id - 1].arg[i] & arg[i].type)
			&& (op_tab[op_id - 1].arg[i] != arg[i].type))
		{
			return (false);
		}
		++i;
//		else if ((arg_byte >> (2 * i) & REG_CODE) == REG_CODE &&
//			!(op_tab[op_id - 1].arg[3 - i] & T_REG))
//		{
//			return (false);
//		}
//		else if ((arg_byte >> (2 * i) & IND_CODE) == IND_CODE &&
//			!(op_tab[op_id - 1].arg[3 - i] & T_IND))
//		{
//			return (false);
//		}
//		else if (!(arg_byte >> (2 * i) & 3) && (op_tab[op_id - 1].arg[3 - i]))
//		{
//			return (false);
//		}
	}
	return (true);
}

bool	arg_read(t_general *data, t_carriage *carriage, size_t arg_cod)
{
	int i;
	size_t tmp_position;

	i = 3;
	ft_memset(carriage->arg, 0, sizeof(carriage->arg));
//	if (op_tab[carriage->op_id - 1].octal)
//	{
//		carriage->position += 1;
//	}
		tmp_position = carriage->position + 1;
		while (i > 0)
		{
			if ((arg_cod >> (2 * i) & DIR_CODE) == DIR_CODE)
			{
				read_dir(data, &carriage->arg[3 - i], tmp_position, DIR_SIZE - 2 * op_tab[carriage->op_id - 1].label);
				tmp_position = (tmp_position + DIR_SIZE - 2 * op_tab[carriage->op_id - 1].label) % MEM_SIZE;
			}
			else if ((arg_cod >> (2 * i) & REG_CODE) == REG_CODE)
			{
				read_reg(data, carriage, &carriage->arg[3 - i], tmp_position);
				tmp_position = (tmp_position + 1) % MEM_SIZE;
			}
			else if ((arg_cod >> (2 * i) & IND_CODE) == IND_CODE)
			{
				read_ind(data, carriage->position, &carriage->arg[3 - i], tmp_position);
				tmp_position = (tmp_position + IND_SIZE) % MEM_SIZE;
			}
			--i;
		}
		carriage->position = tmp_position;
	return (valid_arg(carriage->arg, carriage->op_id));
}
