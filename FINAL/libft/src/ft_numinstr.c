/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numinstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:36:47 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/20 19:37:08 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_numinstr(char *str)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '+')
		++i;
	else if (str[i] == '-')
		++i;
	while (ft_isdigit(str[i]))
		++i;
	return (i);
}
