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

static void		check_nulls(int fd)
{
	int				i;
	int				ret;
	unsigned char	buff[4];

	i = 0;
	ret = read(fd, &buff, 4);
	if (ret == -1)
		error_msg("error reading file!");
	if (ret < 4)
		error_msg("NULL error!");
	while (i < 4)
	{
		if (buff[i] != 0)
			error_msg("NULL error!");
		i++;
	}
}

static int		check_players_size(int fd)
{
	unsigned char	buff[4];
	int				ret;
	unsigned int	size;

	size = 0;
	ret = read(fd, &buff, 4);
	if (ret == -1)
		error_msg("error reading file!");
	if (ret < 4)
		error_msg("error with player's size!");
	size = buff[0] << 24;
	size |= buff[1] << 16;
	size |= buff[2] << 8;
	size |= buff[3];
	return (size);
}

static char		*check_name(int fd, int len)
{
	char	buff[PROG_NAME_LENGTH + 1];
	int		ret;

	ret = read(fd, &buff, len);
	if (ret == -1)
		error_msg("error reading file!");
	if (ret < len)
		error_msg("error: player's name is less than it needed");
	return (ft_strdup(buff));
}

static void		check_magic(int fd)
{
	int				ret;
	unsigned int	magic;
	unsigned char	buff[4];

	ret = read(fd, &buff, 4);
	if (ret == -1)
		error_msg("error reading file!");
	if (ret < 4)
		error_msg("invalid magic number!");
	magic = buff[0] << 24;
	magic |= buff[1] << 16;
	magic |= buff[2] << 8;
	magic |= buff[3];
	if (magic != COREWAR_EXEC_MAGIC)
		error_msg("invalid magic number!");
}

t_player		*player(t_general *data, char **argv, int *i, int id)
{
	t_player	*pl;
	int			fd;

	pl = (t_player *)malloc(sizeof(t_player));
	ft_bzero(pl, sizeof(t_player));
	if ((fd = open(argv[*i], O_RDONLY)) < 0)
		error_msg("error opening file!");
	check_magic(fd);
	pl->name = check_name(fd, PROG_NAME_LENGTH);
	check_nulls(fd);
	pl->size = check_players_size(fd);
	if (pl->size < 1)
		error_msg("error: wrong player's size");
	if (pl->size > CHAMP_MAX_SIZE)
		error_msg("error: player is too big");
	pl->comment = check_comment(fd, COMMENT_LENGTH);
	check_nulls(fd);
	pl->code = check_players_code(fd, pl->size);
	pl->id = id;
	pl->next = NULL;
	data->pl_nbr += 1;
	close(fd);
	return (pl);
}
