/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:45:26 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/23 09:01:46 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	print_byte(WINDOW *win, t_byte_infos *byte, int player_id, int val)
{
	if (byte->pc)
		wattron(win, A_STANDOUT);
	if (byte->live)
		wattron(win, COLOR_PAIR(player_id + 4));
	if (byte->op || byte->live)
		wattron(win, A_BOLD);
	wprintw(win, "%.2x", val);
	if (byte->op || byte->live)
		wattroff(win, A_BOLD);
	if (byte->live)
		wattroff(win, COLOR_PAIR(player_id + 4));
	if (byte->pc)
		wattroff(win, A_STANDOUT);
	if (g_corewar.state == STATE_RUNNING)
	{
		if (byte->live)
			byte->live--;
		if (byte->op)
			byte->op--;
	}
}

static void	print_line(WINDOW *win, int width, const char *memory,
										const t_byte_infos *bytemap)
{
	t_byte_infos	*byte;
	int				player_id;
	int				offset;
	int				i;

	i = 0;
	offset = 2;
	while (i < BYTES_PER_LINE)
	{
		offset += 3;
		if (offset > width)
		{
			wprintw(win, "..");
			break ;
		}
		byte = (t_byte_infos *)&bytemap[i];
		if (!(player_id = byte->number))
			player_id = PAIR_GREY;
		wattron(win, COLOR_PAIR(player_id));
		print_byte(win, byte, player_id, memory[i] & 0xff);
		wattroff(win, COLOR_PAIR(player_id));
		waddch(win, ' ');
		i++;
	}
}

void		panel_memory_draw(t_panel *panel, t_cycle_infos *infos)
{
	int		height;
	int		offset;
	int		i;

	i = 0;
	height = MEM_SIZE / BYTES_PER_LINE;
	if (height > panel->size.y - 4)
	{
		height = panel->size.y - 5;
		wmove(panel->win, panel->size.y - 3, 2);
		waddnstr(panel->win, STR_WIN_TOO_SMALL, panel->size.x - 4);
	}
	while (i < height)
	{
		offset = i * BYTES_PER_LINE;
		wmove(panel->win, i + 2, 3);
		print_line(panel->win, panel->size.x - 5,
						&infos->arena[offset], &infos->byte_infos[offset]);
		i++;
	}
}

void		panel_memory_init(t_panel *panel, t_vec2 size)
{
	t_vec2	pos;

	pos.y = 0;
	pos.x = 0;
	size.x -= size.x * WIN_RATIO;
	panel->size.y = size.y;
	panel->size.x = size.x;
	panel->win = newwin(size.y, size.x, pos.y, pos.x);
	wattron(panel->win, COLOR_PAIR(PAIR_BORDER));
	wborder(panel->win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(panel->win, COLOR_PAIR(PAIR_BORDER));
}
