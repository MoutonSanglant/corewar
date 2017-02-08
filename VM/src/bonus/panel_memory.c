/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:45:26 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/08 16:39:45 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	print_line(t_panel *panel, const char *memory, const t_byte_infos *bytemap, int line)
{
	WINDOW	*win;
	int		player_id;
	int		offset;
	int		width;
	int		i;

	i = 0;
	offset = 2;
	win = panel->win;
	width = panel->size.x - 7;
	while (i < BYTES_PER_LINE)
	{
		player_id = bytemap[i].number;
		if (player_id == 0)
			player_id = PAIR_GREY;
		wattron(win, COLOR_PAIR(player_id));
		if (offset >= width)
		{
			wattroff(win, COLOR_PAIR(player_id));
			mvwprintw(win, line, offset, "...");
			break ;
		}
		mvwprintw(win, line, offset, "%.2x", memory[i] & 0xff);
		wattroff(win, COLOR_PAIR(player_id));
		offset += 3;
		i++;
	}
}

void	panel_memory_draw(t_panel *panel, t_cycle_infos *infos)
{
	WINDOW	*win;
	int		i;
	int		offset;
	int		total_lines;

	i = 0;
	total_lines = MEM_SIZE / BYTES_PER_LINE;
	win = panel->win;
	//wclear(win);
	wattron(win, COLOR_PAIR(PAIR_GREY));
	if (total_lines > panel->size.y - 4)
	{
		total_lines = panel->size.y - 5;
		mvwprintw(win, panel->size.y - 3, 2, STR_WIN_TOO_SMALL);
	}
	while (i < total_lines)
	{
		offset = i * BYTES_PER_LINE;
		print_line(panel,
				&infos->arena[offset], &infos->byte_infos[offset], i + 2);
		i++;
	}
	wattroff(win, COLOR_PAIR(PAIR_GREY));
	wrefresh(win);
}

void	panel_memory_init(t_panel *panel, t_vec2 size)
{
	t_vec2	pos;

	pos.y = 0;
	pos.x = 0;
	size.x -= size.x * WIN_RATIO;
	panel->size.x = size.x;
	panel->size.y = size.y;
	panel->win = newwin(size.y, size.x, pos.y, pos.x);
	wattron(panel->win, COLOR_PAIR(PAIR_BORDER));
	wborder(panel->win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(panel->win, COLOR_PAIR(PAIR_BORDER));
}
