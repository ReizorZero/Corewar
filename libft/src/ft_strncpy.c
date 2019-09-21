/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:35:54 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/06 15:49:38 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strncpy(char *destptr, const char *srcptr, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (n > 0)
	{
		while (i < n)
		{
			if (srcptr[j] != '\0')
			{
				destptr[j] = srcptr[j];
				j++;
			}
			else
				destptr[i] = '\0';
			i++;
		}
		if (j == i && srcptr[i - 1] == '\0')
			destptr[j] = '\0';
	}
	return (destptr);
}
