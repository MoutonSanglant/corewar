/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:45:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/08 16:40:20 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	draw_players(WINDOW *win, int line)
{
	t_player	*player;
	int			i;
	int			id;

	i = 0;
	while (i < g_corewar.player_count)
	{
		player = &g_corewar.players[i];
		id = (int)player->id;
		mvwprintw(win, line, 3, "Player %i:", player->number);
		//load_player_colors(id);
		wattron(win, COLOR_PAIR(id));
		mvwprintw(win, line++, 13, "%s", player->name);
		wattroff(win, COLOR_PAIR(id));
		mvwprintw(win, line++, 5, "Last live :      %i", 0);
		mvwprintw(win, line++, 5, "Lives (period) : %i", 0);
		line++;
		i++;
	}
}

void	panel_infos_draw(t_panel *panel, t_cycle_infos *info)
{
	WINDOW	*win;

	win = panel->win;
	//wclear(win);
	wattron(win, A_BOLD);
	mvwprintw(win, 2, 3, "** PAUSE **");
	mvwprintw(win, 4, 3, "CYCLE_TO_DIE: %u", info->cycle_to_die);
	//mvwprintw(win, 5, 3, "CYCLE_DELTA : %u", info->cycle_delta);
	mvwprintw(win, 5, 3, "CYCLE_DELTA : %u", CYCLE_DELTA);
	mvwprintw(win, 6, 3, "NBR_LIVE : %u", info->nbr_live);
	mvwprintw(win, 7, 3, "MAX_CHECKS : %u", info->max_checks);
	mvwprintw(win, 9, 3, "Cycles/second limit: %u", info->cps);
	mvwprintw(win, 12, 3, "Cycle: %u", info->count);
	mvwprintw(win, 14, 3, "Processes: %u", info->running_proc);
	draw_players(win, 17);
	wattroff(win, A_BOLD);
	wrefresh(win);
}

void	panel_infos_init(t_panel *panel, t_vec2 size)
{
	t_vec2	pos;

	pos.y = 0;
	pos.x = 0;
	pos.x = size.x - (size.x * WIN_RATIO) - 1;
	size.x = (size.x * WIN_RATIO) + 1;
	panel->size.x = size.x;
	panel->size.y = size.y;
	panel->win = newwin(size.y, size.x, pos.y, pos.x);
	wattron(panel->win, COLOR_PAIR(PAIR_BORDER));
	wborder(panel->win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(panel->win, COLOR_PAIR(PAIR_BORDER));
}
