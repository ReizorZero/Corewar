/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:54:21 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/22 14:58:17 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t i;

	i = 0;
	if (!*to_find)
		return ((char *)str);
	if (!*str)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == to_find[i])
		{
			while (str[i] == to_find[i])
			{
				i++;
				if (to_find[i] == '\0')
					return ((char *)str);
				else if (str[i] == '\0')
					return (NULL);
			}
			i = 0;
		}
		str++;
	}
	return (NULL);
}
