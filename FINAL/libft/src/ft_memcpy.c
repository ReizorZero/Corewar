/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:09:45 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/20 13:49:00 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t count)
{
	size_t i;

	i = 0;
	while (i < count)
	{
		((unsigned char*)destptr)[i] = ((unsigned char*)srcptr)[i];
		++i;
	}
	return (destptr);
}
