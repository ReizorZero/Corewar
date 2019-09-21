/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:51:44 by rzero             #+#    #+#             */
/*   Updated: 2018/12/13 16:37:52 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*srcc;
	unsigned char	*dstc;

	srcc = (unsigned char*)src;
	dstc = (unsigned char*)dst;
	if (srcc < dstc)
	{
		while ((int)(--len) >= 0)
		{
			*(dstc + len) = *(srcc + len);
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
