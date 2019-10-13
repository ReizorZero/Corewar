/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:45:16 by mshvets           #+#    #+#             */
/*   Updated: 2018/12/12 14:37:19 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char		*ft_strjoinit(char *s1, char *s2)
{
	char *sum;

	if (!s1 || !s2 || !(sum = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcat(sum, s1);
	ft_strcat(sum, s2);
	free(s1);
	return (sum);
}

static t_fdlst	*ft_lstsearch(t_fdlst **head, int fd)
{
	t_fdlst	*crawler;
	t_fdlst	*new;

	if ((crawler = *head))
	{
		while (crawler)
		{
			if (fd == crawler->fd)
				return (crawler);
			crawler = crawler->next;
		}
	}
	if (!(new = (t_fdlst *)malloc(sizeof(*new))))
		return (NULL);
	new->fd = fd;
	new->str = ft_strnew(0);
	new->next = NULL;
	if (*head)
		new->next = *head;
	*head = new;
	return (*head);
}

static char		*ft_strcut(char *str, char *end)
{
	char	*res;

	if (ft_strlen(end) > 0)
		res = ft_strdup(end + 1);
	else
		res = ft_strnew(0);
	free(str);
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	static t_fdlst		*head;
	t_fdlst				*list;
	char				buf[BUFF_SIZE + 1];
	char				*end;
	ssize_t				check;

	check = BUFF_SIZE;
	if (!(line && (list = ft_lstsearch(&head, fd))) || fd < 0)
		return (-1);
	while (!(end = ft_strchr(list->str, '\n')) && check == BUFF_SIZE)
	{
		ft_bzero(buf, BUFF_SIZE + 1);
		if ((check = (int)read(fd, &buf, BUFF_SIZE)) == -1)
			return (-1);
		list->str = ft_strjoinit((list)->str, buf);
	}
	if (!end)
		end = ft_strchr(list->str, '\0');
	if (!(*line = ft_strnew(end - list->str)))
		return (-1);
	*line = ft_strncpy(*line, list->str, (end - list->str));
	list->str = ft_strcut(list->str, end);
	if (!check && !(**line))
		return (0);
	return (1);
}
