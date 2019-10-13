/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:22:01 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/21 16:22:03 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

t_player	*ft_new_player(int id)
{
	t_player	*new;

	if (!(new = (t_player *)ft_memalloc(sizeof(*new))))
		return (NULL);
	new->id = id;
	return (new);
}

void		ft_del_player(t_player **lst_player)
{
	t_player	*crawler;

	while (*lst_player)
	{
		crawler = *lst_player;
		*lst_player = (*lst_player)->next;
		ft_strdel(&crawler->name);
		ft_strdel(&crawler->comment);
		ft_strdel((char **)&crawler->code);
		free(crawler);
		crawler = NULL;
	}
}

void		ft_add_end_player(t_player **lst_player, t_player *new)
{
	t_player *crawler;

	crawler = *lst_player;
	if (crawler)
	{
		while (crawler->next)
			crawler = crawler->next;
		crawler->next = new;
	}
	else
		*lst_player = new;
}

void		ft_add_player(t_player **lst_player, t_player *new)
{
	if (lst_player)
	{
		if (*lst_player)
		{
			new->next = *lst_player;
			*lst_player = new;
		}
		else
			*lst_player = new;
	}
}
