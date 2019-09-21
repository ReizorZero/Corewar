/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:13:07 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/19 17:34:08 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i;

	i = 0;
	if (!*to_find)
		return ((char *)str);
	while (*str && n > 0)
	{
		if (*str == to_find[i])
		{
			while (str[i] == to_find[i] && i < n && str[i])
			{
				++i;
				if (!to_find[i])
					return ((char *)str);
			}
			i = 0;
		}
		++str;
		--n;
	}
	return (NULL);
}
