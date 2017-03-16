/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:21:04 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/16 18:18:15 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void		panel_help_init(t_panel *panel, t_vec2 size)
{
	t_vec2	pos;

	pos.y = size.y - PANEL_HELP_HEIGHT;
	pos.x = size.x - (size.x * WIN_RATIO) - 1;
	size.y = PANEL_HELP_HEIGHT;
	if (size.y > LINES)
		size.y = LINES;
	if (!(g_corewar.flags & FLAG_FULL))
		size.x = size.x - pos.x;
	else
	{
		size.y = 0;
		size.x = 0;
		pos.x = 0;
		pos.y = 0;
	}
	panel->size.y = size.y;
	panel->size.x = size.x;
	panel->win = newwin(size.y, size.x, pos.y, pos.x);
	wattron(panel->win, COLOR_PAIR(PAIR_BORDER));
	wborder(panel->win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(panel->win, COLOR_PAIR(PAIR_BORDER));
}

void		panel_infos_init(t_panel *panel, t_vec2 size)
{
	t_vec2	pos;

	pos.y = 0;
	pos.x = size.x - (size.x * WIN_RATIO) - 1;
	if (!(g_corewar.flags & FLAG_HELP))
		size.y -= PANEL_HELP_HEIGHT - 1;
	if (size.y < 0)
		size.y = 0;
	if (!(g_corewar.flags & FLAG_FULL))
		size.x = size.x - pos.x;
	else
	{
		size.y = 0;
		size.x = 0;
		pos.x = 0;
		pos.y = 0;
	}
	panel->size.y = size.y;
	panel->size.x = size.x;
	panel->win = newwin(size.y, size.x, pos.y, pos.x);
	wattron(panel->win, COLOR_PAIR(PAIR_BORDER));
	wborder(panel->win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(panel->win, COLOR_PAIR(PAIR_BORDER));
	wtimeout(panel->win, g_corewar.cycle_infos.speed);
}

void		panel_memory_init(t_panel *panel, t_vec2 size)
{
	t_vec2	pos;

	pos.y = 0;
	pos.x = 0;
	if (!(g_corewar.flags & FLAG_FULL))
		size.x -= size.x * WIN_RATIO;
	panel->size.y = size.y;
	panel->size.x = size.x;
	panel->win = newwin(size.y, size.x, pos.y, pos.x);
	wattron(panel->win, COLOR_PAIR(PAIR_BORDER));
	wborder(panel->win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(panel->win, COLOR_PAIR(PAIR_BORDER));
}
