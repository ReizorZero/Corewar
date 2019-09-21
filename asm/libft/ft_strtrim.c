/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:18:33 by rzero             #+#    #+#             */
/*   Updated: 2018/12/13 15:38:42 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*copy;

	i = 0;
	if (s != NULL)
	{
		len = ft_strlen(s);
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		j = len - 1;
		while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
			j--;
		copy = ft_strsub(s, (unsigned int)i, (size_t)(j - i + 1));
		if (copy == NULL)
			return (ft_strsub(s, 1, 0));
		return (copy);
	}
	return (NULL);
}
