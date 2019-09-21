/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:41:32 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/27 16:15:50 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	ft_del(void *content, size_t size)
{
	(void)size;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *crawler;
	t_list *new;
	t_list *head;

	head = NULL;
	if ((crawler = lst))
	{
		while (crawler)
		{
			if (!(new = f(crawler)))
			{
				ft_lstdel(&head, ft_del);
				return (NULL);
			}
			ft_lstaddr(&head, new);
			crawler = crawler->next;
		}
	}
	return (head);
}
