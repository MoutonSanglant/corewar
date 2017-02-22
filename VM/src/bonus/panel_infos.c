/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:45:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/22 14:45:41 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	print_infos(WINDOW *win, int width, int line, char *buf)
{
	ft_snprintf(buf, 64, "CYCLE_DELTA :  %u", CYCLE_DELTA);
	wmove(win, line++, 5);
	waddnstr(win, buf, width - 7);
	ft_snprintf(buf, 64, "NBR_LIVE :     %u", NBR_LIVE);
	wmove(win, line++, 5);
	waddnstr(win, buf, width - 7);
	ft_snprintf(buf, 64, "MAX_CHECKS :   %u", MAX_CHECKS);
	wmove(win, line++, 5);
	waddnstr(win, buf, width - 7);
	return (line);
}

static void	draw_players(WINDOW *win, int width, int line, char *buf)
{
	t_player	*player;
	int			id;
	int			i;

	i = 0;
	while (i < g_corewar.player_count)
	{
		player = &g_corewar.players[i];
		id = (int)player->id;
		ft_snprintf(buf, 64, "Player %i: ", player->number);
		wmove(win, line++, 3);
		waddnstr(win, buf, width - 5);
		if ((int)ft_strlen(buf) < width - 5)
		{
			wattron(win, COLOR_PAIR(id));
			waddnstr(win, player->name, width - 16);
			wattroff(win, COLOR_PAIR(id));
		}
		ft_snprintf(buf, 64, "Last live:      %i      ", player->last_live);
		wmove(win, line++, 5);
		waddnstr(win, buf, width - 7);
		ft_snprintf(buf, 16, "Lives (period): %i      ", player->current_lives);
		wmove(win, line++, 5);
		waddnstr(win, buf, width - 7);
		line++;
		i++;
	}
}

void		panel_infos_draw(t_panel *panel, t_cycle_infos *info, int state)
{
	char		buf[64];
	int			width;
	int			line;

	line = 2;
	width = panel->size.x;
	wattron(panel->win, A_BOLD);
	if (state > 0)
		ft_snprintf(buf, 64, "** RUNNING **");
	else
		ft_snprintf(buf, 64, "** PAUSED **");
	wmove(panel->win, line++, 3);
	waddnstr(panel->win, buf, width - 5);
	line++;
	ft_snprintf(buf, 64, "CYCLE_TO_DIE : %u          ", info->cycle_to_die);
	wmove(panel->win, line++, 5);
	waddnstr(panel->win, buf, width - 7);
	line = print_infos(panel->win, width, line, buf);
	line++;
	ft_snprintf(buf, 64, "Cycle: %u          ", info->count);
	wmove(panel->win, line++, 5);
	waddnstr(panel->win, buf, width - 7);
	ft_snprintf(buf, 64, "Cycle duration: %u ms       ", info->speed);
	wmove(panel->win, line++, 5);
	waddnstr(panel->win, buf, width - 7);
	line++;
	ft_snprintf(buf, 64, "Processes: %u          ", info->running_proc);
	wmove(panel->win, line++, 5);
	waddnstr(panel->win, buf, width - 7);
	draw_players(panel->win, width, 16, buf);
	wattroff(panel->win, A_BOLD);
	wrefresh(panel->win);
}

void		panel_infos_init(t_panel *panel, t_vec2 size)
{
	t_vec2	pos;

	pos.y = 0;
	pos.x = 0;
	pos.x = size.x - (size.x * WIN_RATIO) - 1;
	size.x = (size.x * WIN_RATIO) + 2;
	panel->size.x = size.x;
	panel->size.y = size.y;
	panel->win = newwin(size.y, size.x, pos.y, pos.x);
	wattron(panel->win, COLOR_PAIR(PAIR_BORDER));
	wborder(panel->win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(panel->win, COLOR_PAIR(PAIR_BORDER));
}
