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

#include "../../inc/corewar_vm.h"

void	get_val_ldi(t_carriage carriage, int32_t *val, int8_t i)
{
	if (carriage.arg[i].type == T_DIR)
		*val = (int16_t)get_val16bit(carriage.arg[i]);
	else
		*val = (int32_t)get_val32bit(carriage.arg[i]);
}

void	ft_res_init(t_general *data, t_mem *res, uint32_t adds)
{
	res->type = 0;
	res->mem = data->mem_f;
	res->current = &data->mem_f[adds];
	res->size = REG_SIZE;
	res->mem_end = &data->mem_f[MEM_SIZE];
}

void	op_ldi(t_general *data, t_carriage *crg)
{
	uint32_t	adds;
	int32_t		val1;
	int32_t		val2;
	t_mem		res;

	crg->pos_tmp = (crg->pos + 2) % MEM_SIZE;
	if (arg_read(data, crg, data->mem_f[(crg->pos + 1) % MEM_SIZE]))
	{
		get_val_ldi(*crg, &val1, 0);
		get_val_ldi(*crg, &val2, 1);
		adds = (crg->pos + (val1 + val2) % IDX_MOD) % MEM_SIZE;
		ft_res_init(data, &res, adds);
		memory_cpy(&crg->arg[2], res);
		if (data->verb_nbr & 4 && !data->vis)
		{
			ft_printf("P %4d | ldi %d %d r%d\n", crg->nbr, val1, val2,
				get_num_reg(crg, 2));
			ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)"
				"\n", val1, val2, val1 + val2,
				(crg->pos + ((val1 + val2) % IDX_MOD)));
		}
	}
	crg->pos_tmp = crg->pos;
	crg->pos = (crg->pos + show_pc_movement(data, *crg)) % MEM_SIZE;
}
