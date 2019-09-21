/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_specificator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:56:02 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/26 19:53:49 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		ft_specificator(char *str, int *cnt, t_name *spc, va_list ap)
{
	while (str[++(*cnt)])
	{
		if (ft_type(str[*cnt], spc))
		{
			++(*cnt);
			break ;
		}
		else if (str[*cnt] == '.')
			ft_precision(str, spc, cnt, ap);
		else if (ft_flag(str[*cnt], spc))
			;
		else if (ft_atoi(&str[*cnt]) || str[*cnt] == '*')
			ft_width(str, spc, cnt, ap);
		else if (ft_length(str, spc, cnt))
			;
		else
		{
			spc->obj = str[(*cnt)++];
			break ;
		}
	}
}
