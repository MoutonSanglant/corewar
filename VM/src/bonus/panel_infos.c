/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:45:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/22 19:47:27 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	wprint_buf(WINDOW *win, t_vec2 *pos, int width, char *buf)
{
	wmove(win, pos->y, pos->x);
	waddnstr(win, buf, width);
	pos->y += 1;
}

static void	print_infos(t_panel *panel, t_vec2 *pos, char *buf,
														t_cycle_infos *info)
{
	int		width;

	width = panel->size.x - 7;
	pos->x = 5;
	pos->y++;
	ft_snprintf(buf, 64, "CYCLE_TO_DIE : %u          ", info->cycle_to_die);
	wprint_buf(panel->win, pos, width, buf);
	ft_snprintf(buf, 64, "CYCLE_DELTA :  %u", CYCLE_DELTA);
	wprint_buf(panel->win, pos, width, buf);
	ft_snprintf(buf, 64, "NBR_LIVE :     %u", NBR_LIVE);
	wprint_buf(panel->win, pos, width, buf);
	ft_snprintf(buf, 64, "MAX_CHECKS :   %u", MAX_CHECKS);
	wprint_buf(panel->win, pos, width, buf);
	pos->y++;
	ft_snprintf(buf, 64, "Cycle: %u          ", info->count);
	wprint_buf(panel->win, pos, width, buf);
	ft_snprintf(buf, 64, "Cycle duration: %u ms          ", info->speed);
	wprint_buf(panel->win, pos, width, buf);
	pos->y++;
	ft_snprintf(buf, 64, "Processes: %u          ", info->running_proc);
	wprint_buf(panel->win, pos, width, buf);
}

static void	print_players(WINDOW *win, t_vec2 *pos, int width, char *buf)
{
	t_player	*player;
	int			i;

	i = 0;
	pos->y += 2;
	while (i < g_corewar.player_count)
	{
		player = &g_corewar.players[i];
		ft_snprintf(buf, 64, "Player %i: ", player->number);
		pos->x = 3;
		wprint_buf(win, pos, width - 5, buf);
		if ((int)ft_strlen(buf) < width - 5)
		{
			wattron(win, COLOR_PAIR((int)player->id));
			waddnstr(win, player->name, width - 16);
			wattroff(win, COLOR_PAIR((int)player->id));
		}
		ft_snprintf(buf, 64, "Last live:      %u      ", player->last_live);
		pos->x = 5;
		wprint_buf(win, pos, width - 7, buf);
		ft_snprintf(buf, 64, "Lives (period): %u      ", player->current_lives);
		wprint_buf(win, pos, width - 7, buf);
		pos->y++;
		i++;
	}
}

void		panel_infos_draw(t_panel *panel, t_cycle_infos *info)
{
	char		buf[64];
	int			width;
	t_vec2		pos;

	pos.y = 2;
	pos.x = 3;
	width = panel->size.x;
	wattron(panel->win, A_BOLD);
	if (g_corewar.state == STATE_PAUSED)
		ft_snprintf(buf, 64, "** PAUSED **         ");
	else
		ft_snprintf(buf, 64, "** RUNNING **        ");
	wprint_buf(panel->win, &pos, width - 5, buf);
	print_infos(panel, &pos, buf, info);
	print_players(panel->win, &pos, width, buf);
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
	wtimeout(panel->win, g_corewar.cycle_infos.speed);
}
