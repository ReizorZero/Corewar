/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:56:04 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/21 14:56:06 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

t_carriage	*ft_new_carriage(int player, size_t nbr)
{
	t_carriage	*new;

	if (!(new = (t_carriage *)ft_memalloc(sizeof(*new))))
		return (NULL);
	new->reg[0] = reverse_32bits(-player);
	new->pl_id = player;
	new->op_cycles = -1;
	new->nbr = nbr;
	return (new);
}

void		ft_del_lst_carriage(t_carriage **lst_carriage)
{
	t_carriage	*crawler;

	while (*lst_carriage)
	{
		crawler = *lst_carriage;
		*lst_carriage = (*lst_carriage)->next;
		free(crawler);
		crawler = NULL;
	}
}

int			ft_add_end_carriage(t_carriage **lst_carriage, int player,
			size_t nbr)
{
	t_carriage *crawler;

	crawler = *lst_carriage;
	if (crawler)
	{
		while (crawler->next)
			crawler = crawler->next;
		if (!(crawler->next = ft_new_carriage(player, nbr)))
			return (1);
	}
	else
	{
		if (!(*lst_carriage = ft_new_carriage(player, nbr)))
			return (1);
	}
	return (0);
}

int			ft_add_carriage(t_carriage **lst_carriage, int player, size_t nbr)
{
	t_carriage	*new;

	if (lst_carriage)
	{
		if (!(new = ft_new_carriage(player, nbr)))
			return (1);
		if (*lst_carriage)
		{
			new->next = *lst_carriage;
			*lst_carriage = new;
		}
		else
			*lst_carriage = new;
	}
	return (0);
}
