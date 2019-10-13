/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:16:24 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/20 18:10:11 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_print_str(t_name spc, va_list ap, char *str)
{
	int		len;
	int		k;
	char	*str_tmp;

	k = -1;
	str_tmp = ft_strdup(va_arg(ap, char*));
	if (!str_tmp)
		str_tmp = ft_strdup("(null)");
	if (spc.ident_prec && spc.precision < (int)ft_strlen(str_tmp))
		str_tmp[spc.precision] = '\0';
	len = ft_strlen(str_tmp);
	if (spc.width < len)
		spc.width = len;
	str = ft_strnew(spc.width);
	if ((spc.flag & 16) && !(spc.flag & 1))
		ft_memset((void *)str, '0', spc.width);
	else
		ft_memset((void *)str, ' ', spc.width);
	while (++k < len)
		str[(spc.width * (!(spc.flag & 1)) - (len * (!(spc.flag & 1)) - k))] =
			str_tmp[k];
	ft_strdel(&str_tmp);
	return (str);
}
