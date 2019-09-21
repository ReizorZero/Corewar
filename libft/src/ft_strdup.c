/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:43:51 by mshvets           #+#    #+#             */
/*   Updated: 2018/12/07 19:36:38 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *strptr)
{
	char			*new;
	unsigned long	i;
	size_t			len;

	i = 0;
	if (!strptr || !(new = ft_strnew(ft_strlen(strptr))))
		return (NULL);
	len = ft_strlen(strptr);
	while (i <= len)
	{
		new[i] = strptr[i];
		++i;
	}
	return (new);
}
