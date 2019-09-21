/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:07:53 by rzero             #+#    #+#             */
/*   Updated: 2018/12/13 13:32:52 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*occ;

	i = 0;
	len = ft_strlen(s) + 1;
	occ = NULL;
	while (i < len)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
		i++;
	}
	return (occ);
}
