/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:46:58 by mshvets           #+#    #+#             */
/*   Updated: 2018/10/31 16:51:30 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memchr(const void *buf, int ch, size_t count)
{
	unsigned char *str;

	str = (unsigned char *)buf;
	while (count--)
	{
		if (*str == (unsigned char)ch)
			return (str);
		str++;
	}
	return (NULL);
}
