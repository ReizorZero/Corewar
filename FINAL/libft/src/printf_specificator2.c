/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_specificator2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:02:44 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/26 19:02:46 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_type(char c, t_name *spc)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
		|| c == 'u' || c == 'x' || c == 'X' || c == 'f')
	{
		spc->type = c;
		if (c == 'f' && !spc->ident_prec)
			spc->precision = 6;
		return (1);
	}
	return (0);
}

int		ft_flag(char c, t_name *spc)
{
	if (c == '-')
		spc->flag |= 1;
	else if (c == '+')
		spc->flag |= 2;
	else if (c == ' ')
		spc->flag |= 4;
	else if (c == '#')
		spc->flag |= 8;
	else if (c == '0')
		spc->flag |= 16;
	else
		return (0);
	return (1);
}

int		ft_length(char *str, t_name *spc, int *cnt)
{
	if (!ft_strncmp((str + *cnt), "hh", 2))
	{
		spc->length = 2;
		++(*cnt);
	}
	else if (str[*cnt] == 'h')
		spc->length = 1;
	else if (!ft_strncmp((str + *cnt), "ll", 2))
	{
		spc->length = 8;
		++(*cnt);
	}
	else if (str[*cnt] == 'l')
		spc->length = 4;
	else if (str[*cnt] == 'L')
		spc->length = 16;
	else
		return (0);
	return (1);
}

void	ft_precision(char *str, t_name *spc, int *cnt, va_list ap)
{
	spc->precision = 0;
	spc->ident_prec = 1;
	if (str[(*cnt + 1)] == '*')
	{
		++(*cnt);
		spc->precision = va_arg(ap, int);
		if (spc->precision < 0)
		{
			spc->precision = 0;
			spc->ident_prec = 0;
		}
	}
	else if (ft_isalnum(str[(*cnt + 1)]))
	{
		++(*cnt);
		spc->precision = ft_atoi(&str[*cnt]);
		*cnt += ft_numinstr(&str[(*cnt)]) - 1;
	}
	if (spc->precision < 0)
	{
		spc->width = -spc->precision;
		spc->precision = 0;
		spc->flag |= 1;
	}
}

void	ft_width(char *str, t_name *spc, int *cnt, va_list ap)
{
	if (ft_atoi(&str[*cnt]))
	{
		spc->width = ft_atoi(&str[*cnt]);
		*cnt += ft_numinstr(&str[(*cnt)]) - 1;
	}
	else if (str[*cnt] == '*')
	{
		spc->width = va_arg(ap, int);
		if (spc->width < 0)
		{
			spc->width *= -1;
			spc->flag |= 1;
		}
	}
}
