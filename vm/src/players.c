/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:02:33 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/10/08 14:47:15 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

static void		check_nulls(t_general *data, char *file, int fd)
{
	int				i;
	int				ret;
	unsigned char	buff[4];

	i = 0;
	ret = read(fd, &buff, 4);
	if (ret == -1)
		err_cant_read(data, file);
	if (ret < 4)
		err_read_less(data, file);
	while (i < 4)
	{
		if (buff[i] != 0)
			error_msg("Error: no NULL bytes!", data);
		i++;
	}
}

static int		check_players_size(t_general *data, char *file, int fd)
{
	unsigned char	buff[4];
	int				ret;
	unsigned int	size;

	size = 0;
	ret = read(fd, &buff, 4);
	if (ret == -1)
		err_cant_read(data, file);
	if (ret < 4)
		err_read_less(data, file);
	size = buff[0] << 24;
	size |= buff[1] << 16;
	size |= buff[2] << 8;
	size |= buff[3];
	return (size);
}

static char		*check_name_vm(t_general *data, int len, char *file, int fd)
{
	char	buff[PROG_NAME_LENGTH + 1];
	int		ret;

	ret = read(fd, &buff, len);
	if (ret == -1)
		err_cant_read(data, file);
	if (ret < len)
		err_read_less(data, file);
	return (ft_strdup(buff));
}

static void		check_magic(t_general *data, char *file, int fd)
{
	int				ret;
	unsigned int	magic;
	unsigned char	buff[4];

	ret = read(fd, &buff, 4);
	if (ret == -1)
		err_cant_read(data, file);
	if (ret < 4)
		err_read_less(data, file);
	magic = buff[0] << 24;
	magic |= buff[1] << 16;
	magic |= buff[2] << 8;
	magic |= buff[3];
	if (magic != COREWAR_EXEC_MAGIC)
		err_magic_header(data, file);
}

t_player		*player(t_general *data, char **argv, int *i, int id)
{
	t_player	*pl;
	int			fd;

	if (!(pl = (t_player *)ft_memalloc(sizeof(t_player))))
		error_msg("Malloc error!", data);
	ft_bzero(pl, sizeof(t_player));
	if ((fd = open(argv[*i], O_RDONLY)) < 0)
		err_cant_read(data, argv[*i]);
	check_magic(NULL, argv[*i], fd);
	pl->name = check_name_vm(data, PROG_NAME_LENGTH, argv[*i], fd);
	check_nulls(data, argv[*i], fd);
	pl->size = check_players_size(data, argv[*i], fd);
	if (pl->size < 1)
		err_diff_size(data, argv[*i]);
	if (pl->size > CHAMP_MAX_SIZE)
		err_too_large(data, pl->size, argv[*i]);
	pl->comment = check_comment_vm(data, COMMENT_LENGTH, argv[*i], fd);
	check_nulls(data, argv[*i], fd);
	pl->code = check_players_code(fd, pl->size, argv[*i], data);
	pl->id = id;
	pl->next = NULL;
	data->pl_nbr += 1;
	close(fd);
	return (pl);
}
