/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:38:23 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/27 18:58:25 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"
#include "bonus.h"

static void	resize(WINDOW *windows[2])
{
	t_vec2	size;

	getmaxyx(stdscr, size.y, size.x);
	window_destroy(windows[0]);
	window_destroy(windows[1]);
	windows[1] = panel_memory_init(size);
	windows[0] = panel_infos_init(size);
}

static void	draw(WINDOW *win[2], t_cycle_infos *cycle_infos)
{
	refresh();
	panel_memory_draw(win[1]);
	panel_infos_draw(win[0], cycle_infos);
}

void	curses_loop(int (*cycle_fn)(t_cycle_infos *))
{
	WINDOW	*windows[2];
	int		input;
	int		running;
	t_vec2	size;

	running = 0;
	getmaxyx(stdscr, size.y, size.x);
	windows[1] = panel_memory_init(size);
	windows[0] = panel_infos_init(size);
	while (1)
	{
		draw(windows, &g_corewar.cycle_infos);
		input = getch();
		if (input == ' ')
			running = !running;
		if (input == '\n')
			break ;
		if (input == KEY_RESIZE)
			resize(windows);
		if ((running || input == 'n') && !cycle_fn(&g_corewar.cycle_infos))
			break ;
	}
	window_destroy(windows[0]);
	window_destroy(windows[1]);
	endwin();
}

void	curses_init()
{
	initscr();
	cbreak();
	raw();
	noecho();
	curs_set(0);
	halfdelay(1);
	start_color();
	init_pair(1, COLOR_LIGHT_BLACK, COLOR_LIGHT_BLACK);
}
