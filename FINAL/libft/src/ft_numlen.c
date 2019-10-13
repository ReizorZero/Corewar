/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:20:40 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/28 19:15:45 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_numlen(long long int n, int base)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n / base || n % base)
	{
		++len;
		n /= base;
	}
	return (len);
}
