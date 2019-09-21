/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:22:08 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/20 13:53:51 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *destptr, const void *srcptr, size_t n)
{
	size_t i;

	i = 0;
	if (destptr <= srcptr)
	{
		while (i < n)
		{
			((unsigned char *)destptr)[i] = ((unsigned char *)srcptr)[i];
			++i;
		}
	}
	else
	{
		while (n > 0)
		{
			--n;
			((unsigned char *)destptr)[n] = ((unsigned char *)srcptr)[n];
		}
	}
	return (destptr);
}
