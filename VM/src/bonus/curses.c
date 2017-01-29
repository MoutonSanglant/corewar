/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:38:23 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/29 19:31:20 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"
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

static void	draw(t_panel panels[2], t_cycle_infos *cycle_infos)
{
	refresh();
	panel_memory_draw(&panels[0], cycle_infos);
	panel_infos_draw(&panels[1], cycle_infos);
}

void	curses_loop(int (*cycle_fn)(t_cycle_infos *))
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
	while (1)
	{
		if (need_update)
		{
			draw(panels, &g_corewar.cycle_infos);
			need_update = 0;
		}
		input = getch();
		if (input == ' ')
			running = !running;
		if (input == '\n')
			break ;
		if (input == KEY_RESIZE)
		{
			resize(panels);
			need_update = 1;
		}
		if (running || input == 'n')
		{
			if (!cycle_fn(&g_corewar.cycle_infos))
				break ;
			need_update = 1;
		}
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
	init_pair(1, COLOR_LIGHT_BLACK, COLOR_LIGHT_BLACK);
}
