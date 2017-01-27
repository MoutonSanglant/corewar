/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:45:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/27 18:34:01 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"
#include "bonus.h"

void	panel_infos_draw(WINDOW *win, t_cycle_infos *cycle_infos)
{
	wclear(win);
	wattron(win, COLOR_PAIR(1));
	wborder(win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(win, COLOR_PAIR(1));
	wattron(win, A_BOLD);
	mvwprintw(win, 2, 3, "** PAUSE **");
	mvwprintw(win, 4, 3, "CYCLE_TO_DIE: %i", cycle_infos->cycle_to_die);
	mvwprintw(win, 5, 3, "CYCLE_DELTA : ");
	mvwprintw(win, 6, 3, "NBR_LIVE : ");
	mvwprintw(win, 7, 3, "MAX_CHECKS : ");
	mvwprintw(win, 9, 3, "Cycles/second limit: 50");
	mvwprintw(win, 12, 3, "Cycle: %i", cycle_infos->count);
	mvwprintw(win, 14, 3, "Running processes: 1");
	mvwprintw(win, 15, 5, "Last live:");
	mvwprintw(win, 16, 5, "Lives in current period:");
	wattroff(win, A_BOLD);
	wrefresh(win);
}

WINDOW	*panel_infos_init(t_vec2 size)
{
	t_vec2	pos;

	pos.y = 0;
	pos.x = 0;
	pos.x = size.x - (size.x * WIN_RATIO) - 1;
	size.x = (size.x * WIN_RATIO) + 1;
	return (newwin(size.y, size.x, pos.y, pos.x));
}
