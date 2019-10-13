/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:02:00 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/27 17:11:37 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

long double	ft_pow(long int nb, unsigned int power)
{
	if (power == 0)
		return (1);
	else
		return (nb * ft_pow(nb, (power - 1)));
}
