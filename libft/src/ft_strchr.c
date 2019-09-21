/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:17:41 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/19 16:58:56 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *strptr, int ch)
{
	while (*strptr)
	{
		if (*strptr == (char)ch)
			return ((char *)strptr);
		++strptr;
	}
	if (!ch)
		return ((char *)strptr);
	return (NULL);
}
