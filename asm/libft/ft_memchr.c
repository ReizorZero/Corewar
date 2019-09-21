/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:09:49 by rzero             #+#    #+#             */
/*   Updated: 2018/12/13 18:39:51 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;

	i = 0;
	cs = (unsigned char*)s;
	while (i < n)
	{
		if (*cs == (unsigned char)c)
			return (cs);
		cs++;
		i++;
	}
	return (NULL);
}
