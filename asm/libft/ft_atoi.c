/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:01:14 by rzero             #+#    #+#             */
/*   Updated: 2018/12/13 13:41:29 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skip_blanks(const char *str)
{
	while (*str == '\n' || *str == '\t' || *str == ' ' || *str == '\r'
			|| *str == '\f' || *str == '\v')
		str++;
	return ((char*)str);
}

int			ft_atoi(const char *str)
{
	long int n;
	long int sign;

	if (str == NULL)
		return (0);
	n = 0;
	sign = 1;
	str = skip_blanks(str);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+' && sign == 1)
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		n = (n * 10) + (*str++ - '0');
		if (n > 9223372036854775807 && sign == -1)
			return (0);
		if (n >= 9223372036854775807 && sign == 1)
			return (-1);
	}
	return (n * sign);
}
