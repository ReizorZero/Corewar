/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:04:13 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/27 15:46:25 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		--len;
	if ((size_t)i >= len)
		i = 0;
	new = (char *)ft_memalloc(sizeof(*new) * (len - i + 1));
	if (!new)
		return (NULL);
	while (len > 0)
	{
		--len;
		new[len - i] = s[len];
	}
	return (new);
}
