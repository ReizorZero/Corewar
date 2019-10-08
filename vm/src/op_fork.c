/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:50:39 by mshvets           #+#    #+#             */
/*   Updated: 2019/10/01 16:50:40 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

void op_fork(t_general *data, t_carriage *carriage)
{
	int16_t	adds;
	t_carriage	*new;

//	carriage->carry = 0;
	/*
	 * 0b10000000 - DIR in arg[0];
	 */
	carriage->position_tmp = (carriage->position + 1) % MEM_SIZE;
	arg_read(data, carriage, 0b10000000);
	adds = (int16_t)get_val16bit(carriage->arg[0]);
//	if (ft_add_carriage(&data->head_c, 0, 0))
//	{
//		ft_printf("Error: can't create new carriage! PC = %i\n",
//				data->cycles_total + data->cycles_tmp);
//	}
//	ft_memmove(data->head_c, carriage, sizeof(t_carriage));
//	data->head_c->nbr = ++data->num_carriage;
//	data->head_c->position = (carriage->position + adds % IDX_MOD) % MEM_SIZE;if (ft_add_carriage(&data->head_c, 0, 0))
	if (!(new = ft_new_carriage(0, 0)))
	{
		ft_printf("Error: can't create new carriage! PC = %i\n",
				data->cycles_total + data->cycles_tmp);
		ft_mem_clean(data);
		exit(1);
	}
	ft_memmove(new, carriage, sizeof(t_carriage));
	new->position = (carriage->position + adds % IDX_MOD) % MEM_SIZE;
	new->nbr = ++data->num_carriage;
	new->op_cycles = -1;
	new->next = data->head_c;
	data->head_c = new;
	if (data->verb_nbr & 4) //verb_nbr 4
	{
		ft_printf("P %4d | fork %d (%d)\n", carriage->nbr, adds,
				  (int32_t)(carriage->position + adds % IDX_MOD));
	}
	show_pc_movement(*data, *carriage);
	carriage->position = carriage->position_tmp;
}
