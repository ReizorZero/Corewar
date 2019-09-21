/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:07:53 by rzero             #+#    #+#             */
/*   Updated: 2018/12/13 13:33:55 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*occ;
	int		len;
	char	*temp;
	int		i;

	occ = NULL;
	len = ft_strlen(s);
	temp = (char*)s;
	i = 0;
	while (len >= 0)
	{
		if (s[len] == (char)c)
		{
			while (i < len)
			{
				temp++;
				i++;
			}
			return (temp);
		}
		len--;
	}
	return (occ);
}
