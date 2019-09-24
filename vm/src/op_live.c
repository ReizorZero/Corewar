/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:44:44 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/22 18:44:47 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void op_live(t_carriage *data, t_mem *arg)
{
//	live %1 - 0101 0000 0001 0100 0000
	char mem[] = "0100000001";
	unsigned int	dir;
	t_carriage		crwl;

	ft_memset(&crwl, 0, sizeof(crwl));
	crwl.player = 1;
	crwl.op_cycles = 0;
	crwl.live = 1;
	crwl.position = 1;
//	dir = ft_atoi(mem_f[crwl.position]);

}