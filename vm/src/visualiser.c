//
// Created by Mykhailo SHVETS on 2019-10-11.
//
#include "../inc/corewar_vm.h"

WINDOW *g_mem;
WINDOW *g_info;

void ft_set_color(t_general *data, unsigned int size, int cnt, int clr)
{
	int i;

	i = 0;
	while (size-- > 0)
	{
		data->map_clr[cnt + size].cycle = -1;
		data->map_clr[cnt + size].clr = clr;
	}
}

void	set_color_carriages(t_general *data)
{
	t_carriage *carr;

	carr = data->head_c;
	while (carr)
	{
		data->map_clr[carr->pos].clr = (data->map_clr[carr->pos].clr % 4) + 4;
		if (carr->pos != carr->pos_tmp)
			data->map_clr[carr->pos_tmp].clr = (data->map_clr[carr->pos_tmp].clr) % 4;
		carr = carr->next;
	}
}

//static void draw_carriages(t_general *data)
//{
//	int pos_x;
//	int pos_y;
//	t_carriage *carr;
//
//	carr = data->head_c;
//	while(carr)
//	{
//		wattron(g_mem, COLOR_PAIR(1));
//		pos_x = (carr->pos % 64) + 2;
//		pos_y = (carr->pos / 64) + 3;
//		mvwprintw(g_mem, pos_y, pos_x, "%02x", data->mem_f[carr->pos]);
//		carr = carr->next;
//	}
//	wattroff(g_mem, COLOR_PAIR(1));
//}

static void draw_mem(t_general *data)
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
		if (data->map_clr[i].cycle < 0)
			wattron(g_mem, COLOR_PAIR(data->map_clr[i].clr));
		else if (data->map_clr[i].cycle > 0)
		{
			wattron(g_mem, COLOR_PAIR(data->map_clr[i].clr) | A_BOLD);//set bold
			--(data->map_clr[i].cycle);
		}
		else
			wattron(g_mem, COLOR_PAIR(13));
//		else
//			data->map_clr[i].clr = 0;
		mvwprintw(g_mem, r, c, "%02x", data->mem_f[i]);
//		wattroff(g_mem, COLOR_PAIR(2));
		if (data->map_clr[i].cycle < 0)
			wattroff(g_mem, COLOR_PAIR(data->map_clr[i].clr));
		else if (data->map_clr[i].cycle > 0)
			wattroff(g_mem, COLOR_PAIR(data->map_clr[i].clr) | A_BOLD);
		else
			wattroff(g_mem, COLOR_PAIR(13));
		c += 3;
		i++;
	}
//	wattroff(g_mem, COLOR_PAIR(2));
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
	set_color_carriages(data);
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
		wattron(g_info, COLOR_PAIR(i));
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
	init_color(16, 500, 500, 500);
	init_color(17, 800, 0, 0);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_CYAN);
	init_pair(8, COLOR_BLACK, COLOR_YELLOW);
	init_pair(9, COLOR_WHITE, COLOR_GREEN);
	init_pair(10, COLOR_WHITE, COLOR_BLUE);
	init_pair(11, COLOR_WHITE, COLOR_CYAN);
	init_pair(12, COLOR_WHITE, COLOR_YELLOW);
	init_pair(13, 16, COLOR_BLACK);
}

void vis_init(t_general *data)
{
	initscr();
	g_mem = newwin(70, 196, 0, 0);
	g_info = newwin(70, 35, 0, 197);
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