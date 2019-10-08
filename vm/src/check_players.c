/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:24:45 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/09/29 13:47:36 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

char			*check_comment(int fd, int len, char *file)
{
	char	buff[COMMENT_LENGTH + 1];
	int		ret;

	ret = read(fd, &buff, len);
	if (ret == -1)
		err_cant_read(file);
	if (ret < len)
		err_read_less(file);
	return (ft_strdup(buff));
}

uint8_t			*check_players_code(int fd, int len, char *file)
{
	int				ret;
	uint8_t			*buff;
	uint8_t			check[1];

	if (!(buff = malloc(len)))
		error_msg("Malloc error!");
	ret = read(fd, buff, len);
	if (ret == -1)
		err_cant_read(file);
	if (ret < len)
		err_read_less(file);
	ret = 0;
	if ((ret = read(fd, &check, 1)) != 0)
		err_diff_size(file);
	return (buff);
}

void			before_start(t_general *data)
{
	t_player	*tmp;
	uint8_t		i;
	int pos;
	int			count;

	i = 1;
	count = 0;
	while (i <= data->pl_nbr)
	{
		tmp = get_by_id(data, i);
		ft_memcpy(&data->mem_f[count], tmp->code, tmp->size);
		count += MEM_SIZE / data->pl_nbr;
		i++;
	}
    //print_arena(data);
	i = 1;
	pos = 0;
	while (i <= data->pl_nbr)
	{
		if (ft_add_carriage(&data->head_c, i, ++data->num_carriage))
			error_msg("Error: can't create new carriage!");
		data->head_c->position = pos;
	 	pos += MEM_SIZE / data->pl_nbr;
		i++;
	}
	data->lst_live_plr = data->pl_nbr;
	data->cycles_to_die = CYCLE_TO_DIE;
}
