/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:48:07 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/09/29 13:53:40 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

t_player	*get_by_id(t_general *data, uint8_t id)
{
	t_player *tmp;

	tmp = data->head_p;
	while (tmp)
	{
		if (tmp->id == id)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int			is_free_id(t_general *data, uint8_t id)
{
	t_player *tmp;

	tmp = data->head_p;
	while (tmp)
	{
		if (tmp->id == id)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		check_n_id(t_general *data)
{
	t_player *tmp;

	tmp = data->head_p;
	while (tmp)
	{
		if (tmp->id != 0 && tmp->id > data->pl_nbr)
		{
			error_msg("Error: -n number is bigger than total nbr of players!",
				data);
		}
		tmp = tmp->next;
	}
}

void		check_id(t_general *data)
{
	t_player	*tmp;
	uint8_t		i;

	tmp = data->head_p;
	check_n_id(data);
	i = 1;
	while (tmp)
	{
		if (tmp->id == 0)
		{
			while (is_free_id(data, i))
				i++;
			tmp->id = i;
		}
		tmp = tmp->next;
	}
}
