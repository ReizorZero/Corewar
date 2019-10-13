/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_dot_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:44:22 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 13:44:24 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		get_file_fd(t_asm *the_asm)
{
	int fd;

	fd = open(the_asm->dot_s_file_name, O_RDONLY);
	if (fd == -1)
		ERROR(ERROR_OPEN_FILE, the_asm->dot_s_file_name);
	return (fd);
}

void	close_file(int fd, char *filename)
{
	if (close(fd) == -1)
		ERROR(ERROR_CLOSE_FILE, filename);
}

int		read_from_dot_s(t_asm *the_asm)
{
	char	*s;
	int		fd;

	s = NULL;
	fd = get_file_fd(the_asm);
	while (get_next_line(fd, &s) > 0)
	{
		write_line_to_list(the_asm, s);
		free(s);
	}
	free(s);
	close_file(fd, the_asm->dot_s_file_name);
	parse_lines(the_asm);
	return (1);
}
