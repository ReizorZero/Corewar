/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:40:51 by rzero             #+#    #+#             */
/*   Updated: 2018/12/13 12:25:18 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	char	**filler(const char *s, char **split)
{
	int		n;
	int		i;
	int		start;
	size_t	len;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
			i++;
		else
		{
			start = i;
			len = 0;
			while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
			{
				len++;
				i++;
			}
			if (!(split[n++] = ft_strsub(s, start, len)))
				return (NULL);
		}
	}
	return (split);
}

static	int		count_words(const char *s)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
			i++;
		else
		{
			while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
				i++;
			n++;
		}
	}
	return (n);
}

char			**tabs_split(char const *s)
{
	int		elements;
	char	**split;

	if (s != NULL)
	{
		elements = count_words(s);
		split = (char **)malloc(sizeof(char*) * (elements + 1));
		if (!split)
			return (NULL);
		split = filler(s, split);
		split[elements] = NULL;
		return (split);
	}
	return (NULL);
}
