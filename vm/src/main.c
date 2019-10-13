/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:11:46 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/30 15:13:13 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

void	print_mem(t_general *data)
{
	int i;
	int j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.4p : ", i);
		j = 0;
		while (j < 32)
		{
			ft_printf("%.2x ", data->mem_f[i + j]);
			j++;
		}
		ft_printf("\n");
		i += 32;
	}
}

int		main(int argc, char **argv)
{
	t_general	data;
	int			i;

	i = 0;
	ft_memset(&data, 0, sizeof(data));
	while (i < MEM_SIZE)
	{
		data.map_clr[i].cycle = -1;
		data.map_clr[i++].clr = 5;
	}
	if (argc > 1)
	{
		data.dump_cycle = -1;
		args_checking(&data, argc, argv);
	}
	else
		usage_msg();
	if (data.vis)
		vis_init(&data);
	ft_fight(&data);
	ft_mem_clean(&data);
	return (0);
}
