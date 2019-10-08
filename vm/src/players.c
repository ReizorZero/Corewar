/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:02:33 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/09/29 14:08:48 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

static void		check_nulls(int fd, char *file)
{
	int				i;
	int				ret;
	unsigned char	buff[4];

	i = 0;
	ret = read(fd, &buff, 4);
	if (ret == -1)
		err_cant_read(file);
	if (ret < 4)
		err_read_less(file);
	while (i < 4)
	{
		if (buff[i] != 0)
			error_msg("Error: no NULL bytes!");
		i++;
	}
}

static int		check_players_size(int fd, char *file)
{
	unsigned char	buff[4];
	int				ret;
	unsigned int	size;

	size = 0;
	ret = read(fd, &buff, 4);
	if (ret == -1)
		err_cant_read(file);
	if (ret < 4)
		err_read_less(file);
	size = buff[0] << 24;
	size |= buff[1] << 16;
	size |= buff[2] << 8;
	size |= buff[3];
	return (size);
}

static char		*check_name(int fd, int len, char *file)
{
	char	buff[PROG_NAME_LENGTH + 1];
	int		ret;

	ret = read(fd, &buff, len);
	if (ret == -1)
		err_cant_read(file);
	if (ret < len)
		err_read_less(file);
	return (ft_strdup(buff));
}

static void		check_magic(int fd, char *file)
{
	int				ret;
	unsigned int	magic;
	unsigned char	buff[4];

	ret = read(fd, &buff, 4);
	if (ret == -1)
		err_cant_read(file);
	if (ret < 4)
		err_read_less(file);
	magic = buff[0] << 24;
	magic |= buff[1] << 16;
	magic |= buff[2] << 8;
	magic |= buff[3];
	if (magic != COREWAR_EXEC_MAGIC)
		err_magic_header(file);
}

t_player		*player(t_general *data, char **argv, int *i, int id)
{
	t_player	*pl;
	int			fd;

	if (!(pl = (t_player *)malloc(sizeof(t_player))))
		error_msg("Malloc error!");
	ft_bzero(pl, sizeof(t_player));
	if ((fd = open(argv[*i], O_RDONLY)) < 0)
		err_cant_read(argv[*i]);
	check_magic(fd, argv[*i]);
	pl->name = check_name(fd, PROG_NAME_LENGTH, argv[*i]);
	check_nulls(fd, argv[*i]);
	pl->size = check_players_size(fd, argv[*i]);
	if (pl->size < 1)
		err_diff_size(argv[*i]);
	if (pl->size > CHAMP_MAX_SIZE)
		err_too_large(argv[*i], pl->size);
	pl->comment = check_comment(fd, COMMENT_LENGTH, argv[*i]);
	check_nulls(fd, argv[*i]);
	pl->code = check_players_code(fd, pl->size, argv[*i]);
	pl->id = id;
	pl->next = NULL;
	data->pl_nbr += 1;
	close(fd);
	return (pl);
}
