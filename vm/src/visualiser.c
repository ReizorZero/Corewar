/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:21:09 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/10/14 16:33:38 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

WINDOW *g_mem;
WINDOW *g_info;

void		ft_set_color(t_general *data, unsigned int size, int cnt, int clr)
{
	while (size-- > 0)
	{
		if (clr < 5)
		{
			data->map_clr[(cnt + size) % MEM_SIZE].cycle = 0;
			data->map_clr[(cnt + size) % MEM_SIZE].clr = clr;
		}
		if (clr > 5)
		{
			data->map_clr[(cnt + size) % MEM_SIZE].cycle = 50;
			data->map_clr[(cnt + size) % MEM_SIZE].clr = clr % 5;
		}
	}
}

void		set_color_carriages(t_general *data)
{
	t_carriage *c;

	c = data->head_c;
	while (c)
	{
		data->map_clr[c->pos].clr = (data->map_clr[c->pos].clr % 5) + 5;
		if (data->map_clr[c->pos].clr == 5)
			data->map_clr[c->pos].clr = 10;
		if (c->pos != c->pos_tmp && data->map_clr[c->pos_tmp].clr < 10 &&
			(data->map_clr[c->pos_tmp].clr % 5))
			data->map_clr[c->pos_tmp].clr = (data->map_clr[c->pos_tmp].clr) % 5;
		else if (c->pos != c->pos_tmp && data->map_clr[c->pos_tmp].clr == 10)
			data->map_clr[c->pos_tmp].clr = 5;
		c = c->next;
	}
}

void		vis_print_winner(t_player *winner)
{
	wattron(g_info, COLOR_PAIR(winner->id) | A_BOLD);
	mvwprintw(g_info, 30, 3, "Congratulations! The winner is...");
	mvwprintw(g_info, 32, 3, "%s", winner->name);
	wattroff(g_info, COLOR_PAIR(winner->id) | A_BOLD);
	wrefresh(g_info);
	while ((getch()) != 27)
		;
	delwin(g_mem);
	delwin(g_info);
	endwin();
	exit(1);
}

static void	vis_keyboard(t_general *data)
{
	char ch;

	ch = getch();
	if (ch == 32)
	{
		wattron(g_info, COLOR_PAIR(32) | A_BOLD);
		data->delay = data->delay ? FALSE : TRUE;
		nodelay(stdscr, data->delay);
		if (data->delay)
			mvwprintw(g_info, 3, 15, " ** PLAYING ** ");
		else
			mvwprintw(g_info, 3, 15, " **  PAUSE  ** ");
		wattroff(g_info, COLOR_PAIR(32) | A_BOLD);
	}
	if (ch == 27)
	{
		delwin(g_mem);
		delwin(g_info);
		endwin();
		exit(1);
	}
}

void		vis_upd(t_general *data)
{
	vis_keyboard(data);
	print_info(data);
	set_color_carriages(data);
	draw_mem(data);
	refresh();
	wrefresh(g_info);
	wrefresh(g_mem);
}
