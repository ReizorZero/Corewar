/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:17:36 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/09/29 13:24:16 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"

static void	verbosity_fl(t_general *data, char **argv, int *i)
{
	(*i)++;
	if (argv[*i])
		data->verb_nbr = ft_atoi(argv[*i]);
	else
		error_msg("error: invalid nbr in -v option");
	//add smthing
}

static void	dump_fl(t_general *data, char **argv, int *i)
{
	(*i)++;
	if (argv[*i] && *(argv[*i]) >= '0' && *(argv[*i]) <= '9')
		data->dump_cycle = ft_atoi(argv[*i]);
	else
		error_msg("error: invalid nbr in -dump option");
}

static int	right_extention(const char *name)
{
	int	i;

	i = 0;
	while (name[i])
		i++;
	i -= 4;
	if (!(ft_strcmp(&name[i], ".cor")))
		return (1);
	return (0);
}

static void	add_player(t_general *data, char **argv, int *i)
{
	int id;

	id = 0;
	if (!(ft_strcmp("-n", argv[*i])))
	{
		(*i)++;
		if (argv[*i])
		{
			id = ft_atoi(argv[*i]);
			if (id < 1 || id > MAX_PLAYERS)
				error_msg("invalid nbr in -n option");
		}
		else
			error_msg("invalid nbr in -n option");
		(*i)++;
	}
	if (right_extention(argv[*i]))
		ft_add_end_player(&data->head_p, player(data, argv, i, id));
    //else ?
}

void		args_checking(t_general *data, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!(ft_strcmp("-dump", argv[i])))
			dump_fl(data, argv, &i);
		else if (!(ft_strcmp("-n", argv[i])) || right_extention(argv[i]))
			add_player(data, argv, &i);
		else if (!(ft_strcmp("-v", argv[i])))
			verbosity_fl(data, argv, &i);
		else
			usage_msg();
		i++;
	}
	if (data->pl_nbr < 1 || data->pl_nbr > MAX_PLAYERS)
		error_msg("error: wrong number of player's!");
	check_id(data);
	introducing(data);
	before_start(data);
}
