/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:09:02 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/10/08 14:47:59 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

void	print_winner(t_general *data)
{
	t_player *pl;

	if ((pl = get_by_id(data, data->lst_live_plr)))
	{
		if (data->vis)
			vis_print_winner(pl);
		else
			ft_printf("Contestant %i, \"%s\", has won !\n", pl->id, pl->name);
	}
}

void	usage_msg(void)
{
	ft_printf("usage: ./corewar [-dump n | -v n] [-n n] <player.cor>...\n");
	ft_printf("\t%-6sn : %-50s\n", "-dump", "dumps memory after n cycles");
	ft_printf("\t%-6sn : %-50s\n", "-v",
		"verbosity levels, can be added together");
	ft_printf("\t\t\t%-20s\n", "0: show only essentials");
	ft_printf("\t\t\t%-20s\n", "1: show lives");
	ft_printf("\t\t\t%-20s\n", "2: show cycles");
	ft_printf("\t\t\t%-20s\n", "4: show operations (params are NOT litteral)");
	ft_printf("\t\t\t%-20s\n", "8: show death");
	ft_printf("\t\t\t%-20s\n", "16: show PC movement (except for jumps)");
	exit(1);
}

void	error_msg(char *msg, t_general *data)
{
	ft_putendl_fd(msg, 2);
	ft_mem_clean(data);
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

size_t	show_pc_movement(t_general *data, t_carriage carriage)
{
	size_t	i;
	size_t	step;

	i = -1;
	step = g_op_tab[carriage.op_id - 1].octal ? 2 : 1;
	while (++i < g_op_tab[carriage.op_id - 1].n_arg)
	{
		if (carriage.arg[i].type == T_DIR)
			step += DIR_SIZE - 2 * g_op_tab[carriage.op_id - 1].label;
		else if (carriage.arg[i].type == T_REG ||
			carriage.arg[i].type == 16)
			step += 1;
		else if (carriage.arg[i].type == T_IND)
			step += IND_SIZE;
	}
	i = -1;
	if (data->verb_nbr & 16 && !data->vis)
	{
		ft_printf("ADV %d (%.4p -> %.4p) ",
			step, carriage.pos, (carriage.pos + step) % MEM_SIZE);
		while (++i < step)
			ft_printf("%.2x ", data->mem_f[(carriage.pos + i) % MEM_SIZE]);
		ft_printf("\n");
	}
	return (step);
}
