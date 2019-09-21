/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:14:03 by rzero             #+#    #+#             */
/*   Updated: 2018/12/12 15:12:07 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nextlink;

	while ((*alst) != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		nextlink = (*alst)->next;
		free(*alst);
		*alst = nextlink;
	}
	free(nextlink);
}
