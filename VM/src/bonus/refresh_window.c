/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 19:00:22 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/23 20:19:22 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	refresh_window(t_win *win)
{
	/*
	if (win->caption)
	{
		mvprintw(GAME_Y(LINES, 0) + GAME_h(LINES), COLS / 2
				- ft_strlen(win->caption) / 2, win->caption);
		mvprintw(GAME_Y(LINES, 0) + GAME_h(LINES) + 1, COLS / 2
				- ft_strlen(win->caption2) / 2, win->caption2);
	}
	*/
	refresh();
	clear();
	wborder(win->self, '.', '-', '+', '*', ',', '|', '\\', '/');
	//wborder(win->self, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(win->self);
	delwin(win->self);
	win->self = newwin(win->h, win->w, win->y, win->x);
	box(win->self, 0, 0);
	wrefresh(win->self);
	keypad(win->self, TRUE);
	/*
	if (win->blank_line)
		ft_strdel(&win->blank_line);
	win->blank_line = ft_strnew(win->w / 4);
	win->blank_line = (char *)ft_memset((void *)win->blank_line, ' ',
							win->w / 4 - 1);
							*/
	wattrset(win->self, A_STANDOUT | A_BOLD | COLOR_PAIR(1));
	mvwprintw(win->self, 0, (win->w - ft_strlen(win->title)) / 2,
							win->title);
	wattroff(win->self, A_STANDOUT | A_BOLD | COLOR_PAIR(1));
}
