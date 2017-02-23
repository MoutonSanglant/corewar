/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:45:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/23 14:32:27 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	print_aff(WINDOW *win, t_vec2 *pos, int width)
{
	char	buf[64];
	char	*p_val;
	int		*aff;

	pos->x = 3;
	pos->y++;
	aff = g_corewar.cycle_infos.aff;
	p_val = (char *)&aff[2];
	ft_snprintf(buf, 64, "Last 'aff':");
	wprint_buf(win, pos, width, buf);
	ft_snprintf(buf, 64, "  process %i", aff[0]);
	wprint_buf(win, pos, width, buf);
	ft_snprintf(buf, 64, "  r%i = [%.2x %.2x %.2x %.2x]", aff[1],
										p_val[0] & 0xff,
										p_val[1] & 0xff,
										p_val[2] & 0xff,
										p_val[3] & 0xff);
	wprint_buf(win, pos, width, buf);
	ft_snprintf(buf, 64, "  carry = ");
	wprint_buf(win, pos, width, buf);
	if ((int)ft_strlen(buf) < width)
	{
		wattroff(win, A_BOLD);
		wattron(win, COLOR_PAIR((aff[3]) ? 1 : 2) | A_STANDOUT);
		if (aff[3])
			waddnstr(win, "TRUE", width - 11);
		else
			waddnstr(win, "FALSE", width - 11);
		wattroff(win, COLOR_PAIR((aff[3]) ? 1 : 2) | A_STANDOUT);
		wattron(win, A_BOLD);
	}
}

static void	print_infos(WINDOW *win, t_vec2 *pos, int width, t_cycle_infos *info)
{
	char	buf[64];

	pos->x = 3;
	pos->y++;
	ft_snprintf(buf, 64, "CYCLE_TO_DIE : %u          ", info->cycle_to_die);
	wprint_buf(win, pos, width, buf);
	ft_snprintf(buf, 64, "CYCLE_DELTA :  %u", CYCLE_DELTA);
	wprint_buf(win, pos, width, buf);
	ft_snprintf(buf, 64, "NBR_LIVE :     %u", NBR_LIVE);
	wprint_buf(win, pos, width, buf);
	ft_snprintf(buf, 64, "MAX_CHECKS :   %u", MAX_CHECKS);
	wprint_buf(win, pos, width, buf);
	pos->y++;
	ft_snprintf(buf, 64, "Cycle: %u          ", info->count);
	wprint_buf(win, pos, width, buf);
	ft_snprintf(buf, 64, "Cycle duration: %u ms          ", info->speed);
	wprint_buf(win, pos, width, buf);
	pos->y++;
	ft_snprintf(buf, 64, "Processes: %u          ", info->running_proc);
	wprint_buf(win, pos, width, buf);
}

static void	print_players(WINDOW *win, t_vec2 *pos, int width)
{
	char		buf[64];
	t_player	*player;
	int			i;

	i = 0;
	pos->y += 2;
	while (i < g_corewar.player_count)
	{
		player = &g_corewar.players[i];
		ft_snprintf(buf, 64, "Player %i: ", player->number);
		pos->x = 3;
		wprint_buf(win, pos, width, buf);
		if ((int)ft_strlen(buf) < width)
		{
			wattron(win, COLOR_PAIR(player->id));
			waddnstr(win, player->name, width - 11);
			wattroff(win, COLOR_PAIR(player->id));
		}
		ft_snprintf(buf, 64, "Last live:      %u      ", player->last_live);
		pos->x = 5;
		wprint_buf(win, pos, width - 2, buf);
		ft_snprintf(buf, 64, "Lives (period): %u      ", player->current_lives);
		wprint_buf(win, pos, width - 2, buf);
		pos->y++;
		i++;
	}
}

static void	print_winner(WINDOW *win, t_vec2 *pos, int width)
{
	char		buf[64];
	t_player	*player;

	player = g_corewar.cycle_infos.winner;
	pos->x = 3;
	ft_snprintf(buf, 64, STR_WINNER);
	wprint_buf(win, pos, width - 5, buf);
	wattron(win, COLOR_PAIR(player->id));
	if ((int)ft_strlen(buf) < width - 5)
		waddnstr(win, player->name, width - 19);
	wattroff(win, COLOR_PAIR(player->id));
	ft_snprintf(buf, 64, STR_PRESS_ANY);
	wprint_buf(win, pos, width - 5, buf);
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
	print_infos(panel->win, &pos, width - 7, info);
	print_aff(panel->win, &pos, width - 5);
	print_players(panel->win, &pos, width - 5);
	if (g_corewar.state == STATE_DONE)
		print_winner(panel->win, &pos, width);
	wattroff(panel->win, A_BOLD);
}
