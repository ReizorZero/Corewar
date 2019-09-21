/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:52:01 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/26 20:40:08 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int		ft_print_c_or_nthng(t_name spc, va_list ap, char *str, int *i)
{
	char *str_tmp;

	if (spc.width < 1)
		spc.width = 1;
	if (!(str = ft_strnew(spc.width)))
		return (0);
	if (!(str_tmp = ft_strnew(1)))
		return (0);
	if (spc.type == 0)
		str_tmp[0] = spc.obj;
	else
		str_tmp[0] = va_arg(ap, int);
	ft_memset((void *)str, 32, spc.width);
	if (spc.flag >= 16 && !(spc.flag % 2))
		ft_memset((void *)str, '0', spc.width);
	str[(spc.width - 1) * (!(spc.flag % 2))] = str_tmp[0];
	ft_strdel(&str_tmp);
	if (spc.type == 'c')
		*i += (int)write(1, str, spc.width);
	else
		*i += (int)write(1, str, ft_strlen(str));
	ft_strdel(&str);
	return (1);
}

static int		ft_prnt(t_name spc, va_list ap, int *i)
{
	char *str;

	str = NULL;
	if (spc.type == 'c' || spc.type == 0)
	{
		if (!ft_print_c_or_nthng(spc, ap, str, i))
			return (0);
		return (1);
	}
	else if (spc.type == 's')
		str = ft_print_str(spc, ap, str);
	else if (spc.type == 'p')
		str = ft_print_p(spc, ap, str);
	else if (spc.type == 'd' || spc.type == 'i')
		str = ft_print_di(spc, ap, str);
	else if (spc.type == 'u' || spc.type == 'o' || spc.type == 'x' || spc.type
	== 'X')
		str = ft_print_uox(spc, ap, str);
	else if (spc.type == 'f')
		str = ft_print_f(spc, ap, str);
	if (!str)
		return (0);
	*i += (int)write(1, str, ft_strlen(str));
	ft_strdel(&str);
	return (1);
}

static t_name	ft_spec_init(void)
{
	t_name	spc;

	spc.flag = 0;
	spc.width = 0;
	spc.ident_prec = 0;
	spc.precision = 0;
	spc.length = 0;
	spc.type = 0;
	spc.obj = 0;
	return (spc);
}

int				ft_printf(const char *format, ...)
{
	int		cnt;
	t_name	spc;
	va_list ap;
	int		i;

	cnt = 0;
	i = 0;
	va_start(ap, format);
	while (format[cnt])
	{
		if (format[cnt] == '%')
		{
			spc = ft_spec_init();
			ft_specificator((char *)format, &cnt, &spc, ap);
			if (!ft_prnt(spc, ap, &i))
			{
				va_end(ap);
				return (-1);
			}
		}
		else
			i += (int)write(1, &format[cnt++], 1);
	}
	va_end(ap);
	return (i);
}
