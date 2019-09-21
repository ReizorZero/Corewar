/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:00:44 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/20 18:29:43 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*ft_read_p(t_name spc, va_list ap)
{
	int					len;
	char				*str_tmp;
	char				*str_prec;
	unsigned long long	num;

	num = va_arg(ap, unsigned long long int);
	str_tmp = ft_uitoa_base(num, 16);
	if (spc.ident_prec && !spc.precision && !num)
		str_tmp[0] = '\0';
	len = spc.precision - ft_strlen(str_tmp);
	if (len < 0)
		len = 0;
	if (!(str_prec = ft_strnew(len)))
		return (NULL);
	ft_memset((void *)str_prec, '0', len);
	str_tmp = ft_strjoinl(str_prec, str_tmp);
	if (!(spc.flag & 16) || (spc.flag & 1) || spc.ident_prec)
	{
		str_tmp = ft_strjoinl("0x", str_tmp);
	}
	ft_strdel(&str_prec);
	return (str_tmp);
}

char		*ft_print_p(t_name spc, va_list ap, char *str)
{
	int		len;
	int		k;
	char	*str_tmp;

	k = -1;
	if (!(str_tmp = ft_read_p(spc, ap)))
		return (NULL);
	len = ft_strlen(str_tmp);
	spc.width = spc.width < len ? len : spc.width;
	if (!(str = ft_strnew(spc.width)))
		return (NULL);
	if ((spc.flag & 16) && !(spc.flag % 2) && !spc.ident_prec)
	{
		spc.width = spc.width - 2 < len ? len : spc.width - 2;
		ft_memset((void *)str, '0', spc.width);
	}
	else
		ft_memset((void *)str, ' ', spc.width);
	while (++k < len)
		str[(spc.width * (!(spc.flag % 2)) -
		(len * (!(spc.flag % 2)) - k))] = str_tmp[k];
	if ((spc.flag & 16) && !(spc.flag % 2) && !spc.ident_prec)
		str = ft_strjoinl("0x", str);
	ft_strdel(&str_tmp);
	return (str);
}
