/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:02:17 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/22 18:15:45 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strcat(char *destptr, const char *srcptr)
{
	int i;

	i = 0;
	while (destptr[i])
		i++;
	while (*srcptr)
		destptr[i++] = *srcptr++;
	destptr[i] = '\0';
	return (destptr);
}
