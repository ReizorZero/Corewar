/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:05:08 by mshvets           #+#    #+#             */
/*   Updated: 2018/12/07 19:35:31 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_itoa_base(int n, int base)
{
	long int	num;
	char		*mas;
	char		*str;
	int			len;

	mas = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	len = ft_numlen(n, base);
	if ((num = n) < 0 && base == 10)
		++len;
	if (num < 0)
		num *= -1;
	if (!(str = ft_strnew(len)))
		return (0);
	str[0] = '0';
	if (n < 0 && base == 10)
		str[0] = '-';
	while (num / base || num % base)
	{
		str[--len] = mas[num % base];
		num /= base;
	}
	return (str);
}
