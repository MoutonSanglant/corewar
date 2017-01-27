/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:45:26 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/27 16:55:33 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	panel_memory_draw(WINDOW *win)
{
	wclear(win);
	wattron(win, COLOR_PAIR(1));
	wborder(win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(win, COLOR_PAIR(1));
	//window_print("infos");
	mvwprintw(win, 1, 2, "memory");
	wrefresh(win);
}

WINDOW	*panel_memory_init(t_vec2 size)
{
	t_vec2	pos;

	pos.y = 0;
	pos.x = 0;
	size.x -= size.x * WIN_RATIO;
	return (newwin(size.y, size.x, pos.y, pos.x));
}
