/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:11:17 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/20 14:46:48 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlen(const char *strptr)
{
	size_t len;

	len = 0;
	if (strptr)
	{
		while (strptr[len])
			++len;
	}
	return (len);
}
