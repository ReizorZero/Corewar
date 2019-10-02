/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:18:18 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/01 15:18:20 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void op_st(t_general *data, t_carriage *carriage)
{
	carriage->position_tmp = carriage->position + 2;
	if (arg_read(data, carriage, data->mem_f[carriage->position + 1]))
	{
		memory_cpy(&carriage->arg[1], carriage->arg[0]);
		carriage->carry = 0;
	}
	carriage->position = carriage->position_tmp;
}
