/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:30:18 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/20 19:42:11 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoinl(char *s1, char *s2)
{
	char *sum;

	if (!s1 || !s2 || !(sum = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcat(sum, s1);
	ft_strcat(sum, s2);
	free(s2);
	return (sum);
}
