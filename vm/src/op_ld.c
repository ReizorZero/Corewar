/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:45:55 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/27 18:45:58 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

t_mem	*memory_cpy(t_mem *dest, t_mem *src)
{
	size_t i;

	i = 0;
	while (i < src->total_s)
	{
		if (dest->current == (dest->mem + dest->total_s))
			dest->current = dest->mem;
		if (src->current == (src->mem + src->total_s))
			src->current = src->mem;
		ft_memmove(dest->current, src->current, 1);
		++i;
		++(dest->current);
		++(src->current);
	}
	return (dest);
}

void op_ld(t_general *data, t_carriage *carriage)
{
//	if (carriage->arg[0].type == T_DIR)
//	{
		memory_cpy(&carriage->arg[1], &carriage->arg[0]);
//	}
//	else if (carriage->arg[0].type == T_IND)
//	{
//		;
//	}
//	if (*(int*)carriage->arg[0].mem == 0)
	carriage->carry = !(*(uint32_t*)carriage->arg[0].mem);
}
