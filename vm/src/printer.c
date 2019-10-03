/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:09:02 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/09/29 14:14:40 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void	usage_msg(void)
{
	ft_printf("usage: ./corewar [-dump n | -v n] [-n n] <player.cor> ...\n");
	ft_printf("\t%s - %s\n", "-dump n", "dumps memory after n cycles");
	ft_printf("\t%s - %s\n", "-v n", "verbosity levels, can be added together");
	ft_printf("\t\t%-20s\n", "0: show only essentials");
	ft_printf("\t\t%-20s\n", "1: show lives");
	ft_printf("\t\t%-20s\n", "2: show cycles");
	ft_printf("\t\t%-20s\n", "4: show operations");
	ft_printf("\t\t%-20s\n", "8: show death");
	ft_printf("\t\t%-20s\n", "16: show PC movement"); //except for jumps?
	exit(1);
}

void	error_msg(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	introducing(t_general *data)
{
	t_player	*pl;
	int			i;

	i = 1;
	ft_printf("Introducing contestants...\n");
	while (i <= data->pl_nbr)
	{
		pl = get_by_id(data, i);
		ft_printf("* Player %u, weighing %d bytes, \"%s\" (\"%s\") !\n",
			i, pl->size, pl->name, pl->comment);
		i += 1;
	}
}

void show_pc_movement()
{
	//if verb_nbr 16
	//step = carriage-tmp_position - carriage->position;
	int i;

	i = 0;
	ft_printf("ADV %d (%.4p -> %.4p) ", 
		step, carriage->position, carriage->position + step);
	while(i < step)
	{
		ft_printf("%.2x ", data->mem_f[(carriage->position + i)
			% MEM_SIZE]);
		i++;
	}
}