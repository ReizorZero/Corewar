/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:01:24 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/19 17:15:12 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *strptr, int ch)
{
	char *find;

	find = NULL;
	while (*strptr)
	{
		if (*strptr == (char)ch)
			find = (char *)strptr;
		++strptr;
	}
	if (!ch)
		return ((char *)strptr);
	return (find);
}
