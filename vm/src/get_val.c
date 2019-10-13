/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:20:06 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/06 14:20:20 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

int			get_num_reg(t_carriage *carriage, int n)
{
	return (((uint32_t *)carriage->arg[n].current - carriage->reg) + 1);
}

uint32_t	get_val32bit(t_mem src)
{
	t_mem val;

	ft_memset(&val, 0, sizeof(t_mem));
	val.mem = &val;
	val.size = src.size;
	val.mem_end = &val.mem[val.size];
	val.current = val.mem;
	memory_cpy(&val, src);
	return (reverse_32bits(*(uint32_t *)val.mem));
}

uint32_t	reverse_32bits(uint32_t p_int)
{
	return (p_int >> 24 | p_int << 24 | ((p_int >> 8) & 0xff00)
		| ((p_int << 8) & 0xff0000));
}

uint16_t	get_val16bit(t_mem src)
{
	t_mem val;

	ft_memset(&val, 0, sizeof(t_mem));
	val.mem = &val;
	val.size = src.size;
	val.mem_end = &val.mem[val.size];
	val.current = val.mem;
	memory_cpy(&val, src);
	return (reverse_16bits(*(uint16_t *)val.mem));
}

uint16_t	reverse_16bits(uint16_t p_int)
{
	return (p_int >> 8 | p_int << 8);
}
