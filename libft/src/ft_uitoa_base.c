/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:00:25 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/20 18:05:57 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_uitoa_base(unsigned long long n, int base)
{
	unsigned long long	num;
	char				*mas;
	char				*str;
	int					len;

	len = 0;
	if (!(num = n))
		len = 1;
	mas = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	while (n / base || n % base)
	{
		++len;
		n /= base;
	}
	if (!(str = ft_strnew(len)))
		return (0);
	str[0] = '0';
	while (num / base || num % base)
	{
		str[--len] = mas[num % base];
		num /= base;
	}
	return (str);
}
