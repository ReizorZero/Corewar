//
// Created by Mykhailo SHVETS on 2019-10-06.
//

#include "../inc/corewar_vm.h"

void	ft_check_live_carriage(t_general *data)
{
	t_carriage	*crwl;
	t_carriage	*prv_crwl;

	crwl = data->head_c;
	prv_crwl = NULL;
	while (crwl)
	{
//		if (crwl->live)
//		if (crwl->live && (long int)crwl->lst_live_cycle <= data->cycles_to_die + data->cycles_total)
		if (crwl->live && (long int)crwl->lst_live_cycle > data->cycles_total && data->cycles_to_die > 0)
		{
			crwl->live = 0;
			prv_crwl = crwl;
			crwl = crwl->next;
		}
//		else if (!crwl->live && !prv_crwl)
//		else if ((long int)crwl->lst_live_cycle > data->cycles_to_die + data->cycles_total)
//		else if ((long int)crwl->lst_live_cycle < data->cycles_total && !prv_crwl)
		else if (!prv_crwl)
		{
			data->head_c = crwl->next;
			if (data->verb_nbr & 8) //verb_nbr 8
			{
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", crwl->nbr,
						  ((data->cycles_total + data->cycles_tmp) - crwl->lst_live_cycle), data->cycles_to_die);
			}
			free(crwl);
			crwl = NULL;
			crwl = data->head_c;
		}
//		else if (!crwl->live && prv_crwl)
//		else if ((long int)crwl->lst_live_cycle > data->cycles_to_die + data->cycles_total)
//		else if ((long int)crwl->lst_live_cycle < data->cycles_total && prv_crwl)
		else if (prv_crwl)
		{
			prv_crwl->next = crwl->next;
			if (data->verb_nbr & 8) //verb_nbr 8
			{
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", crwl->nbr,
						  ((data->cycles_total + data->cycles_tmp) - crwl->lst_live_cycle), data->cycles_to_die);
			}
			free(crwl);
			crwl = NULL;
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