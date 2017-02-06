/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:38:23 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/06 16:42:07 by tdefresn         ###   ########.fr       */
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

static void	draw(t_panel panels[2], t_cycle_infos *infos, t_player *players)
{
	refresh();
	panel_memory_draw(&panels[0], infos);
	panel_infos_draw(&panels[1], infos, players);
}

void	curses_loop(int (*cycle_fn)(t_cycle_infos *, t_player *),
														t_player *players)
{
	t_panel	panels[2];
	int		input;
	int		running;
	int		need_update;
	t_vec2	size;

	need_update = 1;
	running = 0;
	getmaxyx(stdscr, size.y, size.x);
	panel_memory_init(&panels[0], size);
	panel_infos_init(&panels[1], size);
	init_memory(&g_corewar.cycle_infos, players);
	draw(panels, &g_corewar.cycle_infos, players);
	input = 0;
	while ((input = getch()) != '\n')
	{
		if (input == ' ')
			running = !running;
		if (input == KEY_RESIZE)
		{
			resize(panels);
			need_update = 1;
		}
		if (running || input == 'n')
		{
			if (!cycle_fn(&g_corewar.cycle_infos, players))
				break ;
			need_update = 1;
		}
		if (need_update)
			draw(panels, &g_corewar.cycle_infos, players);
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
	//halfdelay(1);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(10, COLOR_LIGHT_BLACK, COLOR_LIGHT_BLACK);
	init_pair(11, COLOR_LIGHT_BLACK, COLOR_BLACK);
}
