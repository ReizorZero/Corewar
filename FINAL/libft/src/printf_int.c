/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:12:38 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/22 20:12:40 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static long long	ft_read_di_len(t_name spc, va_list ap)
{
	if (spc.length == 1)
		return ((short int)va_arg(ap, int));
	if (spc.length == 2)
		return ((char)va_arg(ap, int));
	if (spc.length == 4)
		return (va_arg(ap, long int));
	if (spc.length == 8)
		return (va_arg(ap, long long int));
	return (va_arg(ap, int));
}

static char			*ft_read_di(t_name spc, long long int num)
{
	char	*str_prec;
	char	*str_tmp;
	int		len;

	str_tmp = ft_uitoa_base(num < 0 ? -num : num, 10);
	if (spc.ident_prec && !spc.precision && !num)
		str_tmp[0] = '\0';
	if ((len = spc.precision - ft_strlen(str_tmp)) < 0)
		len = 0;
	if (!(str_prec = ft_strnew(len)))
		return (NULL);
	ft_memset((void *)str_prec, '0', len);
	str_tmp = ft_strjoinl(str_prec, str_tmp);
	ft_strdel(&str_prec);
	if (!(spc.flag & 16) || spc.ident_prec || spc.flag & 1)
	{
		if (num < 0)
			str_tmp = ft_strjoinl("-", str_tmp);
		else if (spc.flag & 2)
			str_tmp = ft_strjoinl("+", str_tmp);
		else if (spc.flag & 4)
			str_tmp = ft_strjoinl(" ", str_tmp);
	}
	return (str_tmp);
}

static char			*ft_zero_check_di(t_name *spc, long double num, char *str,
		int len)
{
	if ((spc->flag & 16) && !(spc->flag & 1) && !spc->ident_prec)
	{
		if (spc->width == len && (num < 0 || spc->flag & 2 || spc->flag & 4))
			spc->width += 1;
		str = ft_strnew(spc->width - 1);
		ft_memset((void *)str, '0', spc->width - 1);
		if (num < 0)
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

char				*ft_print_di(t_name spc, va_list ap, char *str)
{
	long long int	num;
	int				len;
	int				k;
	char			*str_tmp;

	k = -1;
	num = ft_read_di_len(spc, ap);
	if (!(str_tmp = ft_read_di(spc, num)))
		return (NULL);
	len = ft_strlen(str_tmp);
	if (spc.width < len)
		spc.width = len;
	str = ft_zero_check_di(&spc, num, str, len);
	while (++k < len)
		str[(spc.width * (!(spc.flag & 1))
		- (len * (!(spc.flag & 1)) - k))] = str_tmp[k];
	ft_strdel(&str_tmp);
	return (str);
}
