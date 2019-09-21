/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:15:38 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/27 15:57:18 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char		*ft_new(const char *s, char **end, char c)
{
	char	*arr;

	if (!(*end = ft_strchr(s, c)))
		*end = ft_strchr(s, '\0');
	if (!(arr = ft_strnew(*end - s)))
		return (NULL);
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	char	*end;
	size_t	count;
	size_t	i;

	if (!(i = 0) && !s)
		return (NULL);
	count = ft_cntwrd(s, c);
	if (!(arr = (char **)ft_memalloc(sizeof(*arr) * (count + 1))))
		return (NULL);
	while (*s && i < count)
	{
		if (*s != c)
		{
			if (!(arr[i] = ft_new(s, &end, c)))
			{
				ft_strdeli(arr, i);
				return (NULL);
			}
			ft_memcpy(arr[i++], s, (end - s));
			s = end;
		}
		++s;
	}
	return (arr);
}
