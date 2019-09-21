/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:16:51 by rzero             #+#    #+#             */
/*   Updated: 2018/12/13 12:32:47 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cdst;
	unsigned char	*csrc;

	i = 0;
	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	while (i < n)
	{
		if (*csrc != (unsigned char)c)
			*cdst++ = *csrc++;
		else
		{
			*cdst++ = *csrc++;
			return (cdst);
		}
		i++;
	}
	return (NULL);
}
