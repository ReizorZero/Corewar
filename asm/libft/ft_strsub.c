/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:43:11 by rzero             #+#    #+#             */
/*   Updated: 2018/12/12 15:48:40 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		sub = (char*)malloc(sizeof(char) * len + 1);
		if (!sub)
			return (NULL);
		sub[len] = '\0';
		while (i < len)
		{
			sub[i] = s[start];
			i++;
			start++;
		}
		return (sub);
	}
	return (NULL);
}
