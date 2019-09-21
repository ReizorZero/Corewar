/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:10:30 by rzero             #+#    #+#             */
/*   Updated: 2018/12/12 15:41:52 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result;

	i = 0;
	if (s != NULL && f != NULL)
	{
		result = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!result)
			return (NULL);
		result[ft_strlen(s)] = '\0';
		while (s[i] != '\0')
		{
			result[i] = f(i, s[i]);
			i++;
		}
		return (result);
	}
	return (NULL);
}
