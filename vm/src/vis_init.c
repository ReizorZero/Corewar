/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:21:00 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/10/13 16:36:27 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

WINDOW		*g_mem;
WINDOW		*g_info;

static void	draw_settings(t_general *data, int i, int r, int c)
{
	if (data->map_clr[i].cycle > 0)
		wattron(g_mem, COLOR_PAIR(data->map_clr[i].clr) | A_BOLD);
	else
		wattron(g_mem, COLOR_PAIR(data->map_clr[i].clr));
	mvwprintw(g_mem, r + 1, c + 1, "%02x", data->mem_f[i]);
	if (data->map_clr[i].cycle > 0)
	{
		--(data->map_clr[i].cycle);
		if (data->map_clr[i].cycle == 0)
			data->map_clr[i].clr %= 5;
		wattroff(g_mem, COLOR_PAIR(data->map_clr[i].clr) | A_BOLD);
	}
	else
		wattroff(g_mem, COLOR_PAIR(data->map_clr[i].clr));
}

void		draw_mem(t_general *data)
{
	int i;
	int c;
	int r;

	i = 0;
	c = 2;
	r = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			r++;
			c = 2;
		}
		draw_settings(data, i, r, c);
		c += 3;
		i++;
	}
}

static void	coloring(void)
{
	start_color();
	init_color(16, 500, 500, 500);
	init_color(17, 800, 0, 0);
	init_color(18, 1000, 750, 790);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, 17, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, 16, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, 17);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);
	init_pair(9, COLOR_BLACK, COLOR_YELLOW);
	init_pair(10, 16, 16);
	init_pair(11, COLOR_WHITE, COLOR_GREEN);
	init_pair(12, COLOR_WHITE, 17);
	init_pair(13, COLOR_WHITE, COLOR_CYAN);
	init_pair(14, COLOR_WHITE, COLOR_YELLOW);
	init_pair(32, 18, COLOR_BLACK);
}

void		print_info(t_general *data)
{
	int			i;
	t_player	*pl;

	wattron(g_info, COLOR_PAIR(32) | A_BOLD);
	mvwprintw(g_info, 5, 3, "It is now %d cycle",
		data->cycles_total + data->cycles_tmp);
	mvwprintw(g_info, 7, 3, "Cycle to die is %d", data->cycles_to_die);
	mvwprintw(g_info, 9, 3, "Proceses now - %d",
		data->num_carriage - data->num_died_carriege);
	wattroff(g_info, COLOR_PAIR(32) | A_BOLD);
	i = 0;
	while (++i <= data->pl_nbr)
	{
		pl = get_by_id(data, i);
		wattron(g_info, COLOR_PAIR(i));
		mvwprintw(g_info, 10 + (i * 3), 3, "Player %d : %s", i, pl->name);
		mvwprintw(g_info, 11 + (i * 3), 3, "\tlast live cycle: %d",
			pl->lst_cycle);
		wattroff(g_info, COLOR_PAIR(i));
	}
	wattron(g_info, COLOR_PAIR(32) | A_BOLD);
	mvwprintw(g_info, 25, 3, "Press [ESC] for exit");
	mvwprintw(g_info, 27, 3, "[SPACE] for pause and user-keybord mode");
	mvwprintw(g_info, 28, 3, "one more [SPACE] to resume the game");
	wattroff(g_info, COLOR_PAIR(32) | A_BOLD);
}

void		vis_init(t_general *data)
{
	initscr();
	g_mem = newwin(68, 197, 0, 0);
	g_info = newwin(68, 50, 0, 197);
	coloring();
	keypad(stdscr, TRUE);
	nodelay(stdscr, data->delay);
	noecho();
	curs_set(0);
	wattron(g_mem, COLOR_PAIR(10));
	wattron(g_info, COLOR_PAIR(10));
	box(g_mem, 0, 0);
	box(g_info, 0, 0);
	wattroff(g_mem, COLOR_PAIR(10));
	wattroff(g_info, COLOR_PAIR(10));
	print_info(data);
	set_color_carriages(data);
	draw_mem(data);
	wattron(g_info, COLOR_PAIR(32) | A_BOLD);
	mvwprintw(g_info, 3, 15, " **  PAUSE  ** ");
	wattroff(g_info, COLOR_PAIR(32) | A_BOLD);
	refresh();
	wrefresh(g_info);
	wrefresh(g_mem);
}
