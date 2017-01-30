/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:45:26 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/30 18:46:02 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

#define BYTES_PER_LINE 64
#define LINE_LENGTH BYTES_PER_LINE * 3


static void	print_line(WINDOW *win, const char *memory, t_vec2 size, int n)
{
	char	line[LINE_LENGTH];
	int		i;

	ft_memset(line, '*', LINE_LENGTH);
	i = 0;
	while (i < BYTES_PER_LINE)
	{
		ft_snprintf(&line[i * 3], 4, "%.2x ", memory[i] & 0xff);
		i++;
	}
	if (size.x < LINE_LENGTH + 5)
	{
		line[size.x - 10] = ' ';
		line[size.x - 9] = '.';
		line[size.x - 8] = '.';
		line[size.x - 7] = '.';
		line[size.x - 6] = '\0';
	}
	line[LINE_LENGTH - 1] = '\0';
	mvwprintw(win, n, 3, "%s", line);
}

void	panel_memory_draw(t_panel *panel, t_cycle_infos *cycle_infos)
{
	WINDOW *win;
	int		i;

	win = panel->win;
	wclear(win);
	i = 0;
	wattron(win, COLOR_PAIR(11));
	while (i < panel->size.y - 4)
	{
		if (i >= MEM_SIZE / BYTES_PER_LINE)
		{
			break ;
		}
		print_line(win, &cycle_infos->arena[i * BYTES_PER_LINE], panel->size, 2 + i);
		i++;
	}
	if (i < MEM_SIZE / BYTES_PER_LINE)
	{
		wmove(win, panel->size.y - 3, 3);
		wclrtoeol(win);
		mvwprintw(win, panel->size.y - 3, 3, STR_WIN_TOO_SMALL);
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
