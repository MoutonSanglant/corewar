/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:38:23 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/23 20:43:31 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

t_win	*win;

void	curses_init()
{
	int		rows;
	int		cols;
	t_vec2	coord;

	coord.x = 0;
	coord.y = 0;

	initscr();
	cbreak();
	raw();
	noecho();
	curs_set(0);

	//getmaxyx(stdscr, rows, cols);
	rows = 0;
	cols = 0;
	refresh();
	win = create_window(coord, rows, cols, "Test");
	wmove(win->self, 1, 2);
	wprintw(win->self, "Hello curses");
	wrefresh(win->self);
	getch();
}

void	curses_release()
{
	endwin();
}
