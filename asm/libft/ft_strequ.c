/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:39:13 by rzero             #+#    #+#             */
/*   Updated: 2018/12/12 15:34:26 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		if (ft_strlen(s1) == ft_strlen(s2))
		{
			while (*s1 != '\0')
			{
				if (*s1 != *s2)
					return (0);
				s1++;
				s2++;
			}
			return (1);
		}
		else
			return (0);
	}
	return (0);
}
