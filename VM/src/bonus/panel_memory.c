/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:45:26 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/29 19:37:08 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

#define LINE_LENGTH 64 * 3

static void		dump_memory(char *terrain, char *str)
{
	int	i;


	i = 0;
	//while (i < MEM_SIZE)
	while (i < 64)
	{
		ft_snprintf(&str[i * 3], 4, "%.2x ", terrain[i] & 0xff);
		i++;
	}
}

static void	print_line(WINDOW *win, char *memory, t_vec2 size, int n)
{
	char	line[LINE_LENGTH];

	(void)size;
	ft_memset(line, '*', LINE_LENGTH);
	//ft_snprintf(line, LINE_LENGTH, memory);
	dump_memory(memory, line);
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

	win = panel->win;
	wclear(win);
	print_line(win, cycle_infos->arena, panel->size, 2);
	wattron(win, COLOR_PAIR(1));
	wborder(win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(win, COLOR_PAIR(1));
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
