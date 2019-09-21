/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_float_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 22:34:07 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/20 18:50:30 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static long double	ft_read_f_len(t_name spc, va_list ap)
{
	if (spc.length == 16)
		return (va_arg(ap, long double));
	return (va_arg(ap, double));
}

static char			*ft_read_f(t_name spc, long double num)
{
	char		*str_tmp;

	if (!(str_tmp = ft_ftoa(num, spc)))
		return (NULL);
	if (!(spc.flag & 16) || spc.flag & 1)
	{
		if (ft_check_sign_double(num))
			str_tmp = ft_strjoinl("-", str_tmp);
		else if (spc.flag & 2)
			str_tmp = ft_strjoinl("+", str_tmp);
		else if (spc.flag & 4)
			str_tmp = ft_strjoinl(" ", str_tmp);
	}
	return (str_tmp);
}

static char			*ft_spec_double(long double num)
{
	if (num != num)
	{
		return (ft_strdup("nan"));
	}
	if (num == 1.0 / 0)
	{
		return (ft_strdup("inf"));
	}
	if (num == -1.0 / 0)
	{
		return (ft_strdup("-inf"));
	}
	return (NULL);
}

static char			*ft_zero_check_f(t_name *spc, long double num, char *str,
		int len)
{
	if ((spc->flag & 16) && !(spc->flag & 1))
	{
		if (spc->width == len && (ft_check_sign_double(num) || spc->flag & 2 ||
		spc->flag & 4))
			spc->width += 1;
		str = ft_strnew(spc->width - 1);
		ft_memset((void *)str, '0', spc->width - 1);
		if (ft_check_sign_double(num))
			str = ft_strjoinl("-", str);
		else if (spc->flag & 2)
			str = ft_strjoinl("+", str);
		else if (spc->flag & 4)
			str = ft_strjoinl(" ", str);
	}
	else
	{
		str = ft_strnew(spc->width);
		ft_memset((void *)str, ' ', spc->width);
	}
	return (str);
}

char				*ft_print_f(t_name spc, va_list ap, char *str)
{
	char		*str_tmp;
	long double	num;
	int			len;
	int			k;

	k = -1;
	num = ft_read_f_len(spc, ap);
	if (!(str_tmp = ft_spec_double(num)))
	{
		if (!(str_tmp = ft_read_f(spc, num)))
			return (NULL);
	}
	len = ft_strlen(str_tmp);
	if (spc.width < len)
		spc.width = len;
	str = ft_zero_check_f(&spc, num, str, len);
	while (++k < len)
		str[(spc.width * (!(spc.flag & 1))
		- (len * (!(spc.flag & 1)) - k))] = str_tmp[k];
	ft_strdel(&str_tmp);
	return (str);
}
