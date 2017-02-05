/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:45:26 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/05 21:20:56 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	print_line(WINDOW *win, t_cycle_infos *infos, int offset,  t_vec2 size, int n)
{
	const char	*memory;
	const t_byte_infos	*bytemap;
	//char	line[LINE_LENGTH];
	int		i;
	int		player_id;

	memory = &infos->arena[offset];
	bytemap = &infos->byte_infos[offset];
	i = 0;
	//ft_memset(line, ' ', LINE_LENGTH);
	//line[LINE_LENGTH - 1] = '\0';
	//endwin();
	//while (i < BYTES_PER_LINE)
	while (i < BYTES_PER_LINE)
	{
		player_id = bytemap[i].number;
		//ft_printf("player %i\n", player_id);
		wattron(win, COLOR_PAIR(player_id));
		//ft_snprintf(&line[i * 3], 3, "%.2x ", memory[i] & 0xff);
		if (4 + 3 * i + 3 > size.x)
		{
			//mvwprintw(win, n, 2 + 3 * i, "...");
			wattroff(win, COLOR_PAIR(player_id));
			mvwprintw(win, n, 2 + 3 * (i - 1), "...");
			break ;
		}
		mvwprintw(win, n, 2 + 3 * i, "%.2x", memory[i] & 0xff);
		wattroff(win, COLOR_PAIR(player_id));
		i++;
	}
	//if (size.x < LINE_LENGTH + 5)
	//	mvwprintw(win, n, 2 + 3 * i, "...", memory[i] & 0xff);
	//	ft_strcpy(&line[size.x - 10], " ...");
	//mvwprintw(win, n, 3, "%s", line);
}

void	panel_memory_draw(t_panel *panel, t_cycle_infos *infos)
{
	WINDOW	*win;
	int		i;

	win = panel->win;
	wclear(win);
	i = 0;
	wattron(win, COLOR_PAIR(11));
	while (i < panel->size.y - 4 && i < MEM_SIZE / BYTES_PER_LINE)
	{
		print_line(win, infos, i * BYTES_PER_LINE, panel->size, 2 + i);
		i++;
	}
	//exit(0);
	if (i < MEM_SIZE / BYTES_PER_LINE)
	{
		wmove(win, panel->size.y - 3, 3);
		wclrtoeol(win);
		mvwprintw(win, panel->size.y - 3, 2, STR_WIN_TOO_SMALL);
	}
	wattron(win, COLOR_PAIR(11));
	wattron(win, COLOR_PAIR(10));
	wborder(win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(win, COLOR_PAIR(10));
	//window_print("infos");
	//mvwprintw(win, 1, 2, "memory");
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
}
