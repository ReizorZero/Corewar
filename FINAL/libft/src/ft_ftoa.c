/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:05:47 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/26 19:40:48 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int			ft_doub_numlen(long double n, int base)
{
	int len;

	len = 0;
	while (n / base >= 1)
	{
		++len;
		n /= base;
	}
	return (len);
}

static long double	ft_round(long double num, t_name spc)
{
	unsigned long int		k;
	long double				n;
	long double				del;

	n = num >= 0 ? num : -num;
	del = ft_pow(10, spc.precision);
	k = n * ft_pow(10, spc.precision + 1);
	if (k % 10 >= 5)
		n = n + 1 / del;
	return (n);
}

char				*ft_ftoa(long double num, t_name spc)
{
	int					pow;
	char				*str;
	int					i;
	unsigned long int	k;

	i = 0;
	num = ft_round(num, spc);
	pow = ft_doub_numlen(num, 10) + 1;
	if (!(str = ft_strnew(pow + spc.precision + 1)))
		return (NULL);
	while (--pow >= 0)
	{
		k = num / ft_pow(10, pow);
		str[i++] = k % 10 + '0';
		num -= k * ft_pow(10, pow);
	}
	if (spc.precision > 0 || spc.flag & 8)
		str[i++] = '.';
	while (++pow < spc.precision)
	{
		num *= 10;
		k = num;
		str[i++] = k % 10 + '0';
	}
	return (str);
}
