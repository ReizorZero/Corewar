/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:56:33 by mshvets           #+#    #+#             */
/*   Updated: 2018/11/19 16:15:29 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *destptr, const char *srcptr, size_t size)
{
	size_t d_len;
	size_t len;

	d_len = 0;
	len = 0;
	while (destptr[d_len])
		++d_len;
	while (srcptr[len])
		++len;
	if (size < d_len)
		len += size;
	else
		len += d_len;
	destptr += d_len;
	while (*srcptr && size > d_len + 1)
	{
		*(destptr++) = *(srcptr++);
		--size;
	}
	*destptr = '\0';
	return (len);
}
