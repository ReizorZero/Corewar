/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:11:46 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/30 15:13:13 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../inc/corewar_vm.h"
#include <ncurses.h>

WINDOW *g_mem;
WINDOW *g_info;

static void draw_carriages(t_general *data)
{
	int pos_x;
	int pos_y;
	t_carriage *carr;

	carr = data->head_c;
	while(carr)
	{
		wattron(g_mem, COLOR_PAIR(1));
		pos_x = (carr->pos % 64) + 2;
		pos_y = (carr->pos / 64) + 3;
		mvwprintw(g_mem, pos_y, pos_x, "%02x", data->mem_f[carr->pos]);
		carr = carr->next;
	}
	wattroff(g_mem, COLOR_PAIR(1));
}

static void draw_mem(t_general *data)
{
	int i;
	int c;
	int r;

	i = 0;
	c = 2;
	r = 0;
	while (i < 4096)
	{
		if (i % 64 == 0)
		{
			r++;
			c = 2;
		}
		wattron(g_mem, COLOR_PAIR(2));
		mvwprintw(g_mem, r + 2, c + 2, "%02x", data->mem_f[i]);
		wattroff(g_mem, COLOR_PAIR(2));
		c += 3;
		i++;
	}
	wattroff(g_mem, COLOR_PAIR(2));
}

static void vis_game(t_general *data)
{
	char ch;

	wattron(g_info, COLOR_PAIR(2));
	mvwprintw(g_info, 5, 3, "It is now %d cycle", data->cycles_total + data->cycles_tmp);
	mvwprintw(g_info, 6, 3, "Cycle to die is %d", data->cycles_to_die);
	ch = getch();
	if (ch == 32) //space
	{
		mvwprintw(g_info, 4, 3, "--------- ** PAUSE ** ---------");
		refresh();
		wrefresh(g_info);
		while ((ch = getch()) != 32 && ch != 27)
			;
		mvwprintw(g_info, 4, 3, "-------------------------------");
		refresh();
		wrefresh(g_info);
	}
	wattroff(g_info, COLOR_PAIR(2));
	if (ch == 27) //ECS
	{
		delwin(g_mem);
		delwin(g_info);
		endwin();
		exit(1);
	}
	refresh();
	wrefresh(g_info);
	wrefresh(g_mem);
}

void upd(t_general *data)
{
	draw_mem(data);
	//draw_carriages(data);
	vis_game(data);
}

static void print_info(t_general *data)
{
	int i;
	t_player *pl;

	wattron(g_info, COLOR_PAIR(2));
	mvwprintw(g_info, 2, 3, "-------------------------------");
	mvwprintw(g_info, 3, 3, "------- ** GAME INFO ** -------");
	mvwprintw(g_info, 4, 3, "-------------------------------");
	mvwprintw(g_info, 5, 3, "It is now %d cycle", data->cycles_total + data->cycles_tmp);
	mvwprintw(g_info, 6, 3, "Cycle to die is %d", data->cycles_to_die);
	mvwprintw(g_info, 7, 3, "-------------------------------");
	wattroff(g_info, COLOR_PAIR(2));
	i = 1;
	while (i <= data->pl_nbr)
	{
		pl = get_by_id(data, i);
		wattron(g_info, COLOR_PAIR(i + 2));
		mvwprintw(g_info, 8 + (i * 2), 3, "Player %d : %s", i, pl->name);
		pl->color = i + 2;
		wattroff(g_info, COLOR_PAIR(i + 2));
		i++;
	}
	wattron(g_info, COLOR_PAIR(2));
	mvwprintw(g_info, 22, 3, "-------------------------------");
	mvwprintw(g_info, 23, 3, "Press [ESC] for exit");
	mvwprintw(g_info, 24, 3, "                               ");
	mvwprintw(g_info, 25, 3, "Press [SPACE] for pause/resume ");
	mvwprintw(g_info, 26, 3, "-------------------------------");
	wattroff(g_info, COLOR_PAIR(2));
}

static void coloring(void)
{
	start_color();
	init_color(16, 233, 233, 233);
	init_color(17, 800, 0, 0);
	init_pair(1, COLOR_MAGENTA, 16);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, 17, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
}

static void vis_init(t_general *data)
{
	initscr();
	g_mem = newwin(70, 153, 0, 0);
	g_info = newwin(70, 35, 0, 154);
	coloring();
	keypad(stdscr, TRUE);
	//nodelay(stdscr, TRUE);
	noecho();
	wattron(g_mem, COLOR_PAIR(1) | A_BOLD);
	wattron(g_info, COLOR_PAIR(1) | A_BOLD);
	box(g_mem, 0, 0);
	box(g_info, 0, 0);
	wattroff(g_mem, COLOR_PAIR(1) | A_BOLD);
	wattroff(g_info, COLOR_PAIR(1) | A_BOLD);
	print_info(data);
	vis_game(data);
}

void	print_mem(t_general *data)
{
	int i;
	int j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.4p : ", i);
		j = 0;
		while (j < 64)//32!
		{
			ft_printf("%.2x ", data->mem_f[i + j]);
			j++;
		}
		ft_printf("\n");
		i += 64;//32!
	}
}

int		main(int argc, char **argv)
{
	t_general	data;

	ft_memset(&data, 0, sizeof(data));
	if (argc > 1)
	{
		data.dump_cycle = -1;
		args_checking(&data, argc, argv);
	}
	else
		usage_msg();
	if (data.vis)
		vis_init(&data);
	ft_fight(&data);
	ft_mem_clean(&data);
	return (0);
}
