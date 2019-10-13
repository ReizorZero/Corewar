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

#include "../../inc/corewar_vm.h"

void	read_dir(t_general *data, t_mem *arg, size_t position, size_t size)
{
	arg->mem = data->mem_f;
	arg->size = size;
	arg->current = &data->mem_f[position];
	arg->mem_end = &data->mem_f[MEM_SIZE];
	arg->type = T_DIR;
}

void	read_reg(t_general *data, t_carriage *carriage, t_mem *arg,
		size_t position)
{
	arg->mem = &carriage->reg[(uint8_t)data->mem_f[position] - 1];
	arg->size = REG_SIZE;
	arg->current = arg->mem;
	arg->mem_end = arg->mem + REG_SIZE;
	if (data->mem_f[position] > 0 &&
		(uint8_t)data->mem_f[position] <= REG_NUMBER)
	{
		arg->type = T_REG;
	}
	else
		arg->type = 16;
}

void	read_ind(t_general *data, t_carriage *carriage, t_mem *arg,
	size_t position)
{
	t_mem	pointer;
	size_t	adds;

	read_dir(data, &pointer, position, sizeof(int16_t));
	arg->ind_pntr = get_val16bit(pointer);
	if (carriage->op_id == 13)
		adds = (carriage->pos + arg->ind_pntr) % MEM_SIZE;
	else
		adds = (carriage->pos + (arg->ind_pntr % IDX_MOD)) % MEM_SIZE;
	arg->mem = data->mem_f;
	arg->size = REG_SIZE;
	arg->current = &data->mem_f[adds];
	arg->mem_end = &data->mem_f[MEM_SIZE];
	arg->type = T_IND;
}

bool	valid_arg(t_mem *arg, uint8_t op_id)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (!(g_op_tab[op_id - 1].arg[i] & arg[i].type)
			&& (g_op_tab[op_id - 1].arg[i] != arg[i].type))
		{
			return (false);
		}
		++i;
	}
	return (true);
}

bool	arg_read(t_general *data, t_carriage *carriage, size_t arg_cod)
{
	int i;

	i = 4;
	ft_memset(carriage->arg, 0, sizeof(carriage->arg));
	while ((3 - (--i)) < g_op_tab[carriage->op_id - 1].n_arg)
	{
		if ((arg_cod >> (2 * i) & 0b11) == DIR_CODE)
		{
			read_dir(data, &carriage->arg[3 - i], carriage->pos_tmp,
				DIR_SIZE - 2 * g_op_tab[carriage->op_id - 1].label);
			carriage->pos_tmp = (carriage->pos_tmp + DIR_SIZE
				- 2 * g_op_tab[carriage->op_id - 1].label) % MEM_SIZE;
		}
		else if ((arg_cod >> (2 * i) & 0b11) == REG_CODE)
		{
			read_reg(data, carriage, &carriage->arg[3 - i], carriage->pos_tmp);
			carriage->pos_tmp = (carriage->pos_tmp + 1) % MEM_SIZE;
		}
		else if ((arg_cod >> (2 * i) & 0b11) == IND_CODE)
		{
			read_ind(data, carriage, &carriage->arg[3 - i], carriage->pos_tmp);
			carriage->pos_tmp = (carriage->pos_tmp + IND_SIZE) % MEM_SIZE;
		}
	}
	return (valid_arg(carriage->arg, carriage->op_id));
}
