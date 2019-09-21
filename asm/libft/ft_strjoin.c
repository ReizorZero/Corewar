/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:15:55 by rzero             #+#    #+#             */
/*   Updated: 2019/03/05 17:46:24 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*check_null(char const *s1, char const *s2)
{
	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	if (s2 == NULL && s1 != NULL)
		return (ft_strdup(s1));
	return (NULL);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		size;
	int		i;
	int		j;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		join = (char*)malloc(sizeof(char) * (size + 1));
		if (!join)
			return (NULL);
		while (s1[i] != '\0')
		{
			join[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
			join[i++] = s2[j++];
		join[size] = '\0';
		return (join);
	}
	return (check_null(s1, s2));
}
