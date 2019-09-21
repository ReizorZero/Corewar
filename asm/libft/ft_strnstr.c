/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:57:22 by rzero             #+#    #+#             */
/*   Updated: 2018/12/13 13:36:43 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *ndl, size_t len)
{
	size_t i;

	i = 0;
	if (ft_strcmp(hs, ndl) == 0 || ft_strcmp(ndl, "") == 0)
		return ((char*)hs);
	while (hs[i] != '\0')
	{
		if (hs[i] == ndl[0] && i <= (len - ft_strlen(ndl)))
		{
			if (ft_strncmp(&hs[i], ndl, (ft_strlen(ndl))) == 0)
			{
				if (ft_strlen(ndl) <= len)
				{
					while (i > 0)
					{
						hs++;
						i--;
					}
					return ((char*)hs);
				}
			}
		}
		i++;
	}
	return (NULL);
}
