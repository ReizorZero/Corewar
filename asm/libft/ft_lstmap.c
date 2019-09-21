/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:19:46 by rzero             #+#    #+#             */
/*   Updated: 2018/12/12 15:16:49 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*mapped;
	t_list	*first;
	t_list	*applied;
	int		i;

	i = 0;
	if (lst != NULL && f != NULL)
	{
		applied = f(lst);
		mapped = ft_lstnew(applied->content, applied->content_size);
		i++;
		first = mapped;
		while (lst->next != NULL)
		{
			lst = lst->next;
			applied = f(lst);
			mapped->next = ft_lstnew(applied->content, applied->content_size);
			mapped = mapped->next;
			i++;
			if (!mapped)
				return (NULL);
		}
		return (first);
	}
	return (NULL);
}
