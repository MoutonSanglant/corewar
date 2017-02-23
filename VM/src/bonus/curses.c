/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:38:23 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/23 09:18:41 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	init_panels(t_panel panels[2])
{
	t_vec2	size;

	getmaxyx(stdscr, size.y, size.x);
	panel_memory_init(&panels[0], size);
	panel_infos_init(&panels[1], size);
	refresh();
	draw(panels, &g_corewar.cycle_infos);
}

static void	resize(t_panel panels[2])
{
	window_destroy(panels[0].win);
	window_destroy(panels[1].win);
	init_panels(panels);
}

static void	check_basic_input(int input, t_panel panels[2])
{
	if (input == '+')
		wtimeout(panels[1].win, ++g_corewar.cycle_infos.speed);
	else if (input == '-')
		wtimeout(panels[1].win, --g_corewar.cycle_infos.speed);
	else if (input == ' ' && g_corewar.state == STATE_PAUSED)
		g_corewar.state = STATE_RUNNING;
	else if (input == ' ' && g_corewar.state == STATE_RUNNING)
		g_corewar.state = STATE_PAUSED;
	else if (input == KEY_RESIZE)
		resize(panels);
}

void		curses_loop(int (*cycle_fn)(t_cycle_infos *))
{
	t_panel	panels[2];
	int		input;

	init_panels(panels);
	while ((input = wgetch(panels[1].win)) != '\n')
	{
		draw(panels, &g_corewar.cycle_infos);
		check_basic_input(input, panels);
		if (g_corewar.state == STATE_RUNNING || input == 'n' || input == 's')
		{
			if (cycle_fn(&g_corewar.cycle_infos) <= 0)
			{
				g_corewar.state = STATE_DONE;
				draw(panels, &g_corewar.cycle_infos);
				timeout(-1);
				while (getch() == KEY_RESIZE)
					resize(panels);
				break ;
			}
		}
	}
	window_destroy(panels[0].win);
	window_destroy(panels[1].win);
	endwin();
}

void		curses_init(void)
{
	initscr();
	cbreak();
	raw();
	noecho();
	curs_set(0);
	start_color();
	load_player_colors();
	init_pair(PAIR_BORDER, COLOR_LIGHT_BLACK, COLOR_LIGHT_BLACK);
	init_pair(PAIR_GREY, COLOR_LIGHT_BLACK, COLOR_BLACK);
	init_memory(&g_corewar.cycle_infos);
}
