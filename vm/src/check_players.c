/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:24:45 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/10/08 14:43:38 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

char		*check_comment_vm(t_general *data, int len, char *file, int fd)
{
	char	buff[COMMENT_LENGTH + 1];
	int		ret;

	ret = read(fd, &buff, len);
	if (ret == -1)
		err_cant_read(data, file);
	if (ret < len)
		err_read_less(data, file);
	return (ft_strdup(buff));
}

uint8_t		*check_players_code(int fd, int len, char *file, t_general *data)
{
	int				ret;
	uint8_t			*buff;
	uint8_t			check[1];

	if (!(buff = ft_memalloc(len)))
		error_msg("Malloc error!", data);
	ret = read(fd, buff, len);
	if (ret == -1)
		err_cant_read(data, file);
	if (ret < len)
		err_read_less(data, file);
	ret = 0;
	if ((ret = read(fd, &check, 1)) != 0)
		err_diff_size(data, file);
	return (buff);
}

static void	making_carriages(t_general *data)
{
	uint8_t		i;
	int			count;

	i = 1;
	count = 0;
	while (i <= data->pl_nbr)
	{
		if (ft_add_carriage(&data->head_c, i, ++data->num_carriage))
			error_msg("Error: can't create new carriage!", data);
		data->head_c->pos = count;
		count += MEM_SIZE / data->pl_nbr;
		i++;
	}
	data->lst_live_plr = data->pl_nbr;
	data->cycles_to_die = CYCLE_TO_DIE;
}

void		before_start(t_general *data)
{
	t_player	*tmp;
	uint8_t		i;
	int			count;

	i = 1;
	count = 0;
	while (i <= data->pl_nbr)
	{
		tmp = get_by_id(data, i);
		ft_memcpy(&data->mem_f[count], tmp->code, tmp->size);
		if (data->vis)
			ft_set_color(data, tmp->size, count, i);
		count += MEM_SIZE / data->pl_nbr;
		i++;
	}
	making_carriages(data);
}
