/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:38:23 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/21 10:17:34 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	resize(t_panel panels[2])
{
	t_vec2	size;

	getmaxyx(stdscr, size.y, size.x);
	window_destroy(panels[0].win);
	window_destroy(panels[1].win);
	panel_memory_init(&panels[0], size);
	panel_infos_init(&panels[1], size);
}

static void	draw(t_panel panels[2], t_cycle_infos *infos, int state)
{
	WINDOW		*win;
	t_player	*player;

	refresh();
	mark_bytes(&g_corewar.cycle_infos);
	panel_memory_draw(&panels[0], infos);
	panel_infos_draw(&panels[1], infos, state);
	if (state > 1)
	{
		player = g_corewar.cycle_infos.winner;
		win = panels[1].win;
		wattron(win, A_BOLD);
		mvwprintw(win, 34, 3, STR_WINNER);
		wattron(win, COLOR_PAIR(player->id));
		mvwprintw(win, 34, ft_strlen(STR_WINNER) + 4, player->name);
		wattroff(win, COLOR_PAIR(player->id));
		mvwprintw(win, 36, 3, STR_PRESS_ANY);
		wattroff(win, A_BOLD);
		wrefresh(win);
		timeout(-1);
		getch();
	}
}

void	curses_loop(int (*cycle_fn)(t_cycle_infos *))
{
	t_panel	panels[2];
	int		input;
	int		state;
	int		need_update;
	t_vec2	size;

	need_update = 1;
	state = 0;
	getmaxyx(stdscr, size.y, size.x);
	panel_memory_init(&panels[0], size);
	panel_infos_init(&panels[1], size);
	init_memory(&g_corewar.cycle_infos);
	draw(panels, &g_corewar.cycle_infos, state);
	input = 0;
	while ((input = getch()) != '\n')
	{
		if (input == ' ')
		{
			state = !state;
			need_update = 1;
		}
		if (input == KEY_RESIZE)
		{
			resize(panels);
			need_update = 1;
		}
		if (state || input == 'n')
		{
			if (cycle_fn(&g_corewar.cycle_infos) <= 0)
			{
				draw(panels, &g_corewar.cycle_infos, 2);
				break ;
			}
			need_update = 1;
		}
		if (need_update)
			draw(panels, &g_corewar.cycle_infos, state);
		need_update = 0;
	}
	window_destroy(panels[0].win);
	window_destroy(panels[1].win);
	endwin();
}

void	curses_init()
{
	initscr();
	cbreak();
	raw();
	noecho();
	curs_set(0);
	timeout(10);
	start_color();
	load_player_colors();
	init_pair(PAIR_BORDER, COLOR_LIGHT_BLACK, COLOR_LIGHT_BLACK);
	init_pair(PAIR_GREY, COLOR_LIGHT_BLACK, COLOR_BLACK);
}
