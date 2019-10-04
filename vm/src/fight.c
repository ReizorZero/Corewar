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

int get_num_reg(t_carriage *carriage, int n)
{
	return ((carriage->reg - (uint32_t *)carriage->arg[n].current) / 4 + 1);
}

uint32_t get_val32bit(t_mem src)
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

uint32_t reverse_32bits(uint32_t pInt)
{
	return (pInt >> 24 | pInt << 24 | ((pInt >> 8) & 0xff00)
		| ((pInt << 8) & 0xff0000));
}

uint16_t get_val16bit(t_mem src)
{
	t_mem val;

	ft_memset(&val, 0, sizeof(t_mem));
	val.mem = &val;
	val.size = src.size;
	val.mem_end = &val.mem[val.size];
	val.current = val.mem;
	memory_cpy(&val, src);
	return (reverse_16bits(*(short *)val.mem));
}

uint16_t reverse_16bits(uint16_t pInt)
{
	return (pInt >> 8 | pInt << 8);
}

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

void	ft_check_live_carriage(t_general *data)
{
	t_carriage	*crwl;
	t_carriage	*prv_crwl;

	crwl = data->head_c;
	prv_crwl = NULL;
	while (crwl)
	{
//		if (crwl->live)
		if (crwl->live && (long int)crwl->lst_live_cycle <= data->cycles_to_die + data->cycles_total)
		{
			crwl->live = 0;
			prv_crwl = crwl;
			crwl = crwl->next;
		}
//		else if (!crwl->live && !prv_crwl)
		else if ((long int)crwl->lst_live_cycle > data->cycles_to_die + data->cycles_total)
		{
			data->head_c = crwl->next;
			free(crwl);
			if (data->verb_nbr & 8) //verb_nbr 8
			{
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", crwl->nbr,
						  ((data->cycles_total + data->cycles_tmp) - crwl->lst_live_cycle), data->cycles_to_die);
			}
			crwl = data->head_c;
		}
//		else if (!crwl->live && prv_crwl)
		else if ((long int)crwl->lst_live_cycle > data->cycles_to_die + data->cycles_total)
		{
			prv_crwl->next = crwl->next;
			free(crwl);
			if (data->verb_nbr & 8) //verb_nbr 8
			{
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", crwl->nbr,
						  ((data->cycles_total + data->cycles_tmp) - crwl->lst_live_cycle), data->cycles_to_die);
			}
			crwl = prv_crwl->next;
		}
	}
}

void start_new_op(t_general *data, t_carriage *crg)
{
	if (data->mem_f[crg->position] > 0 && data->mem_f[crg->position] <= 16)
	{
		crg->op_id = (uint8_t)data->mem_f[crg->position];
		crg->op_cycles = (int)op_tab[crg->op_id - 1].cycles;
	}
	else
	{
		/*
		 * В этом случае необходимо запомнить считанный код, а значение
		 * переменной, хранящей количество циклов до выполнения, оставить
		 * равным нулю.
		 */
		crg->position = (crg->position + 1) % MEM_SIZE;
	}
}

void	set_new_cycle(t_general *data)
{
	if (data->cnt_live >= NBR_LIVE || ++data->num_checks >= MAX_CHECKS)
	{
		data->cycles_to_die -= CYCLE_DELTA;
		if (data->verb_nbr & 2)
			ft_printf("Cycle to die is now %d\n", data->cycles_to_die);
		data->num_checks = 0;
	}
	data->cycles_total += data->cycles_tmp;
	data->cnt_live = 0;
	data->cycles_tmp = 0;
}
void	print_winner(t_general *data)
{
//	t_player *crwl;
//
//	crwl = data->head_p;
//	while (crwl && crwl->id != data->lst_live_plr)
//		crwl = crwl->next;
//	if (crwl->id == data->lst_live_plr)
	t_player *pl;

	if ((pl = get_by_id(data, data->lst_live_plr)))
		ft_printf("Contestant %i, \"%s\", has won !\n", pl->id, pl->name);
}

void	ft_fight(t_general *data)
{
	t_carriage	*crwl = NULL;

	data->cycles_tmp = 1;

	while (data->head_c)
	{
//		if ((data->cycles_total + data->cycles_tmp) > 18489)
//		{
//
//			ft_printf("\n");
//		}
		if (data->verb_nbr & 2) //verb_nbr 2
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
//				if (op_tab[carriage->op_id - 1].octal)
					op_func[crwl->op_id - 1](data, crwl);
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
