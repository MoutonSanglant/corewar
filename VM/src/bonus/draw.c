/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:04:02 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/22 19:05:09 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	draw(t_panel panels[2], t_cycle_infos *infos)
{
	t_player	*player;

	refresh();
	mark_bytes(&g_corewar.cycle_infos);
	panel_memory_draw(&panels[0], infos);
	panel_infos_draw(&panels[1], infos);
	if (g_corewar.state == STATE_DONE)
	{
		player = g_corewar.cycle_infos.winner;
		wattron(panels[1].win, A_BOLD);
		mvwprintw(panels[1].win, 34, 3, STR_WINNER);
		wattron(panels[1].win, COLOR_PAIR(player->id));
		mvwprintw(panels[1].win, 34, ft_strlen(STR_WINNER) + 4, player->name);
		wattroff(panels[1].win, COLOR_PAIR(player->id));
		mvwprintw(panels[1].win, 36, 3, STR_PRESS_ANY);
		wattroff(panels[1].win, A_BOLD);
		wrefresh(panels[1].win);
		timeout(-1);
		getch();
	}
}
