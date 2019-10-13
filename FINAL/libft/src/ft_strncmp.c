/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:51:16 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/19 17:53:33 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	if (n < 1)
		return (0);
	while (n > (i + 1) && str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
			++i;
		else
			break ;
	}
	return (((unsigned char*)str1)[i] - ((unsigned char *)str2)[i]);
}
