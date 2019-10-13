/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:54:26 by mshvets           #+#    #+#             */
/*   Updated: 2018/10/31 18:13:43 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t count)
{
	size_t i;

	i = 0;
	while (count--)
	{
		if (((unsigned char *)ptr1)[i] - ((unsigned char *)ptr2)[i] != 0)
			return (((unsigned char *)ptr1)[i] - ((unsigned char *)ptr2)[i]);
		i++;
	}
	return (0);
}
