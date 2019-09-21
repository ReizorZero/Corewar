/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_oux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:23:08 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/20 22:23:23 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static unsigned long long	ft_read_oux_len(t_name spc, va_list ap)
{
	if (spc.length == 1)
		return (va_arg(ap, unsigned int));
	if (spc.length == 2)
		return (va_arg(ap, unsigned int));
	if (spc.length == 4)
		return (va_arg(ap, unsigned long int));
	if (spc.length == 8)
		return (va_arg(ap, unsigned long long int));
	return (va_arg(ap, unsigned int));
}

static char					*ft_read_base(unsigned long long num, char *str_tmp,
		t_name spc)
{
	if (spc.type == 'u')
		str_tmp = ft_uitoa_base(num, 10);
	else if (spc.type == 'o')
	{
		str_tmp = ft_uitoa_base(num, 8);
		if (spc.flag & 8 && num)
			str_tmp = ft_strjoinl("0", str_tmp);
	}
	else if (spc.type == 'x' || spc.type == 'X')
		str_tmp = ft_uitoa_base(num, 16);
	return (str_tmp);
}

static char					*ft_read_uox(t_name spc, unsigned long long num)
{
	int		len;
	char	*str_tmp;
	char	*str_prec;

	str_tmp = NULL;
	str_tmp = ft_read_base(num, str_tmp, spc);
	if (spc.ident_prec && !spc.precision && !num && !(spc.type == 'o'
		&& spc.flag & 8))
		str_tmp[0] = '\0';
	if ((len = spc.precision - ft_strlen(str_tmp)) < 0)
		len = 0;
	if (!(str_prec = ft_strnew(len)))
		return (NULL);
	ft_memset((void *)str_prec, '0', len);
	str_tmp = ft_strjoinl(str_prec, str_tmp);
	if (spc.flag & 8 && (!(spc.flag & 16) || (spc.flag & 1) || spc.ident_prec))
		if ((spc.type == 'x' || spc.type == 'X') && num)
			str_tmp = ft_strjoinl("0x", str_tmp);
	ft_strdel(&str_prec);
	return (str_tmp);
}

static char					*ft_zero_check_oux(t_name *spc, long double num,
		char *str, int len)
{
	if ((spc->flag & 16) && !(spc->flag % 2) && !spc->ident_prec)
	{
		if ((spc->flag & 8) && (spc->type == 'x' || spc->type == 'X') && num)
			spc->width = spc->width - 2 < len ? len : spc->width - 2;
		ft_memset((void *)str, '0', spc->width);
	}
	else
		ft_memset((void *)str, ' ', spc->width);
	return (str);
}

char						*ft_print_uox(t_name spc, va_list ap, char *str)
{
	int					len;
	int					k;
	char				*str_tmp;
	unsigned long long	num;

	k = -1;
	num = ft_read_oux_len(spc, ap);
	if (!(str_tmp = ft_read_uox(spc, num)))
		return (NULL);
	if (spc.width < (len = ft_strlen(str_tmp)))
		spc.width = len;
	if (!(str = ft_strnew(spc.width)))
		return (NULL);
	str = ft_zero_check_oux(&spc, num, str, len);
	while (++k < len)
		str[(spc.width * (!(spc.flag % 2)) -
			(len * (!(spc.flag % 2)) - k))] = str_tmp[k];
	ft_strdel(&str_tmp);
	if ((spc.flag & 16) && !(spc.flag % 2) && !spc.ident_prec)
		if ((spc.flag & 8) && (spc.type == 'x' || spc.type == 'X') && num)
			str = ft_strjoinl("0x", str);
	if (spc.type == 'X')
		ft_strupcase(str);
	return (str);
}
