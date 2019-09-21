/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sign_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:46:07 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/26 17:46:08 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_check_sign_double(double num)
{
	union u_doub_bit var;

	var.d = num;
	if (var.i & (1ULL << 63))
		return (1);
	return (0);
}
