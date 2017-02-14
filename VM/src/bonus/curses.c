/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:38:23 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/14 21:55:24 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	resize(t_panel panels[2])
{
	t_vec2	size;

	getmaxyx(stdscr, size.y, size.x);
	window_destroy(panels[0].win);
	window_destroy(panels[1].win);
	panel_memory_init(&panels[0], size);
	panel_infos_init(&panels[1], size);
}

static void	draw(t_panel panels[2], t_cycle_infos *infos)
{
	refresh();
	panel_memory_draw(&panels[0], infos);
	panel_infos_draw(&panels[1], infos);
}

void	set_process_cursors(t_cycle_infos *infos)
{
	t_proc	*process;
	int		offset;
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		infos->byte_infos[i].byte_flag = 0;
		i++;
	}
	i = 0;
	while (i < g_corewar.process_count)
	{
		process = &g_corewar.process[i];
		offset = process->pc - infos->arena;
		infos->byte_infos[offset].byte_flag |= BYTE_PC;
		i++;
	}
}

void	curses_loop(int (*cycle_fn)(t_cycle_infos *))
{
	t_panel	panels[2];
	int		input;
	int		running;
	int		need_update;
	t_vec2	size;
	WINDOW	*win;
	t_player	*player;

	need_update = 1;
	running = 0;
	getmaxyx(stdscr, size.y, size.x);
	panel_memory_init(&panels[0], size);
	panel_infos_init(&panels[1], size);
	init_memory(&g_corewar.cycle_infos);
	draw(panels, &g_corewar.cycle_infos);
	input = 0;
	while ((input = getch()) != '\n')
	{
		set_process_cursors(&g_corewar.cycle_infos);
		if (input == ' ')
			running = !running;
		if (input == KEY_RESIZE)
		{
			resize(panels);
			need_update = 1;
		}
		if (running || input == 'n')
		{
			if (cycle_fn(&g_corewar.cycle_infos) <= 0)
			{
				win = panels[1].win;
				player = g_corewar.cycle_infos.winner;
				wattron(win, A_BOLD);
				mvwprintw(win, 34, 3, STR_WINNER);
				wattron(win, COLOR_PAIR(player->id));
				mvwprintw(win, 34, ft_strlen(STR_WINNER) + 4, player->name);
				wattroff(win, COLOR_PAIR(player->id));
				mvwprintw(win, 36, 3, STR_PRESS_ANY);
				wattroff(win, A_BOLD);
				wrefresh(win);
				timeout(-1);
				getch();
				break ;
			}
			need_update = 1;
		}
		if (need_update)
			draw(panels, &g_corewar.cycle_infos);
		need_update = 0;
	}
	window_destroy(panels[0].win);
	window_destroy(panels[1].win);
	endwin();
}

void	curses_init()
{
	initscr();
	cbreak();
	raw();
	noecho();
	curs_set(0);
	timeout(10);
	start_color();
	load_player_colors();
	init_pair(PAIR_BORDER, COLOR_LIGHT_BLACK, COLOR_LIGHT_BLACK);
	init_pair(PAIR_GREY, COLOR_LIGHT_BLACK, COLOR_BLACK);
}
