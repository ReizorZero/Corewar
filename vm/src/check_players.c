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

char			*check_comment(int fd, int len)
{
	char	buff[COMMENT_LENGTH + 1];
	int		ret;

	ret = read(fd, &buff, len);
	if (ret == -1)
		error_msg("error reading file!");
	if (ret < len)
		error_msg("error: player's comment is less than it needed");
	return (ft_strdup(buff));
}

uint8_t	*check_players_code(int fd, int len)
{
	int				ret;
	uint8_t			*buff;
	uint8_t			check[1];

	if (!(buff = malloc(len)))
		error_msg("malloc error!");
	ret = read(fd, buff, len);
	if (ret == -1)
		error_msg("error reading file!");
	if (ret < len)
		error_msg("error: player's comment is less than it was defined");
	ret = 0;
	if ((ret = read(fd, &check, 1)) != 0)
		error_msg("player's code is bigger than is was defined");
	return (buff);
}

void			before_start(t_general *data)
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
		count += MEM_SIZE / data->pl_nbr;
		i++;
	}
    //print_arena(data);
	i = 1;
	while (i <= data->pl_nbr)
	{
		ft_add_carriage(&data->head_c, i, ++data->num_carriage);
		i++;
	}
	data->lst_live_plr = data->pl_nbr;
	data->cycles_to_die = CYCLE_TO_DIE;
}
