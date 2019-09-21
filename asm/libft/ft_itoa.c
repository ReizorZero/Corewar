/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:51:39 by rzero             #+#    #+#             */
/*   Updated: 2018/12/12 16:25:48 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	wordsize(int n)
{
	int size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	if (n == 0)
	{
		return (1);
	}
	if (n == -2147483648)
	{
		return (11);
	}
	while (n > 0)
	{
		n = (n - (n % 10)) / 10;
		size++;
	}
	return (size);
}

static int	check_overflow(int n, char *r)
{
	int is_max;

	if (n == -2147483648)
	{
		*r = '2';
		is_max = 1;
	}
	else
		is_max = 0;
	return (is_max);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		size;

	i = 0;
	size = wordsize(n);
	res = (char*)malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	res[size] = '\0';
	if (n < 0)
	{
		n = n * (-1);
		res[i++] = '-';
	}
	if (n == 0)
		res[i] = '0';
	if (check_overflow(n, &res[i++]) == 1)
		n = 147483648;
	while (n > 0)
	{
		res[size-- - 1] = (n % 10) + '0';
		n = (n - (n % 10)) / 10;
	}
	return (res);
}
