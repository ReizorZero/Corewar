/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:57:22 by rzero             #+#    #+#             */
/*   Updated: 2018/12/13 13:34:20 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;

	i = 0;
	if (ft_strcmp(haystack, needle) == 0 || ft_strcmp(needle, "") == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(&haystack[i], needle, (ft_strlen(needle))) == 0)
			{
				while (i > 0)
				{
					haystack++;
					i--;
				}
				return ((char*)haystack);
			}
		}
		i++;
	}
	return (NULL);
}
