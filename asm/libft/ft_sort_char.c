/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 09:54:28 by rzero             #+#    #+#             */
/*   Updated: 2018/12/13 18:49:59 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_char(char **array, int elnum)
{
	int i;
	int swp_count;

	i = 0;
	swp_count = 0;
	if (array != NULL && elnum > 0)
	{
		while (i < elnum)
		{
			if ((i + 1 != elnum) && (ft_strcmp(array[i], array[i + 1]) > 0))
			{
				ft_swap_char(&array[i], &array[i + 1]);
				swp_count = 1;
			}
			i++;
			if (i == elnum && swp_count == 1)
			{
				swp_count = 0;
				i = 0;
			}
		}
	}
}
