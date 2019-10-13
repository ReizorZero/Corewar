/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srtwrd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:11:33 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/26 20:14:12 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_srtwrd(char **tab)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				swap = tab[j];
				tab[j] = tab[i];
				tab[i] = swap;
			}
			++j;
		}
		++i;
	}
}
