/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:39:46 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/22 18:15:00 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strncat(char *destptr, const char *srcptr, size_t n)
{
	size_t i;

	i = 0;
	while (destptr[i])
		++i;
	while (*srcptr && n > 0)
	{
		destptr[i++] = *srcptr++;
		--n;
	}
	destptr[i] = '\0';
	return (destptr);
}
