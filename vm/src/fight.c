/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:38:13 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/03 12:38:06 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void memory_cpy(t_mem *dest, t_mem src)
{
	size_t i;
//	t_mem dest_cpy;
	void	*current;

	current = dest->current;
	i = 0;
//	dest_cpy = *dest;
	while (i < src.size)
	{
		if (current == dest->mem_end)
			current = dest->mem;
		if (src.current == src.mem_end)
			src.current = src.mem;
		ft_memmove(current, src.current, 1);
		++i;
		current += 1;
		src.current += 1;
	}
}

void	ft_fight(t_general *data)
{
	t_carriage	*crwl = NULL;

	data->cycles_tmp = 1;

	while (data->head_c)
	{
//		if ((data->cycles_total + data->cycles_tmp) == 22544)
//		{
//
//			ft_printf("\n\n\n\n");
//		}
		if (data->verb_nbr & 2)
			ft_printf("It is now cycle %d\n", data->cycles_total + data->cycles_tmp);
		if (data->cycles_tmp + data->cycles_total >= data->dump_cycle && data->dump_cycle >= 0)
		{
			print_mem(data);
			return ;
		}
		crwl = data->head_c;
//		while (crwl && data->cnt_live < NBR_LIVE)
		while (crwl)
		{
			if (crwl->op_cycles < 0)
				start_new_op(data, crwl);
			if (crwl->op_cycles > 0)
				--(crwl->op_cycles);
			if (!crwl->op_cycles)
			{
//				if (g_op_tab[carriage->op_id - 1].octal)
					g_op_func[crwl->op_id - 1](data, crwl);
				--(crwl->op_cycles);
			}
			crwl = crwl->next;
		}
		if (data->cycles_tmp >= data->cycles_to_die)
		{
			ft_check_live_carriage(data);
//			system("leaks VM");
			set_new_cycle(data);
		}
		++data->cycles_tmp;
	}
	print_winner(data);
}
