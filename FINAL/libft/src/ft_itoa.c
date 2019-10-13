/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:39:07 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/28 19:20:01 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_itoa(int n)
{
	long int	num;
	char		*str;
	size_t		len;

	num = n;
	len = ft_numlen(num, 10);
	if (num < 0)
		++len;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num / 10 || num % 10)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
