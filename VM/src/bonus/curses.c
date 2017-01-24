/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:38:23 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/24 15:54:08 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	draw(WINDOW *win[2])
{
	refresh();
	panel_memory_draw(win[1]);
	panel_infos_draw(win[0]);
}

static void	loop()
{
	WINDOW	*windows[2];
	int		input;
	t_vec2	size;

	getmaxyx(stdscr, size.y, size.x);
	windows[1] = panel_memory_init(size);
	windows[0] = panel_infos_init(size);
	draw(windows);
	while ((input = getch()) != ' ')
	{
		if (input == KEY_RESIZE)
			resize(windows);
		draw(windows);
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
	start_color();
	init_pair(1, COLOR_LIGHT_BLACK, COLOR_LIGHT_BLACK);
	loop();
}
