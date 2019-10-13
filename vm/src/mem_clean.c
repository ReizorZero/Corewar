/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:42:54 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/21 17:42:57 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

void	ft_mem_clean(t_general *data)
{
	if (data)
	{
		if (data->head_p)
			ft_del_player(&data->head_p);
		if (data->head_c)
			ft_del_lst_carriage(&data->head_c);
	}
}
