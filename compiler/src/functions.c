/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:43:36 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 13:43:38 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void		arg_cases(int *arg_code, char *rez, int j, int i)
{
	if (arg_code[i] == 1)
	{
		rez[j] = '0';
		rez[j + 1] = '1';
	}
	if (arg_code[i] == 2)
	{
		rez[j] = '1';
		rez[j + 1] = '0';
	}
	if (arg_code[i] == 3)
	{
		rez[j] = '1';
		rez[j + 1] = '1';
	}
}

int			convert_bit_to_int(char *bit)
{
	int		sum;
	int		i;
	int		n;

	n = 8;
	i = n - 1;
	sum = 0;
	while (i != -1)
	{
		if (bit[i] == '1')
			sum += ft_pow(2, n - (i + 1));
		i--;
	}
	return (sum);
}

void		write_null_in_file(t_asm *the_asm, int i)
{
	int	j;

	j = -1;
	if (i < 0)
		ERROR_(TOO_BIG_NAME_COMMENT);
	while (++j != i)
		out_in_file(0, 1, the_asm);
}
