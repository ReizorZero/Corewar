/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 16:17:58 by mshvets           #+#    #+#             */
/*   Updated: 2018/09/08 22:21:02 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_sqtr(int nb)
{
	long long int	i;
	int				res;

	i = 1;
	res = 1;
	while (nb > 0)
	{
		if (nb == 1)
			return (res);
		i = 2;
		while (i <= nb / 2)
		{
			if (nb % (i * i) == 0)
			{
				nb = nb / (i * i);
				res = res * i;
				break ;
			}
			i++;
		}
		if (i > nb / 2 && nb != 1)
			break ;
	}
	return (0);
}
