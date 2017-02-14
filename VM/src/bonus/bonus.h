/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:56:54 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/20 16:56:54 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <ncurses.h>

# include <libft.h>

# include "../corewar.h"

# define BYTES_PER_LINE 64
# define LINE_LENGTH BYTES_PER_LINE * 3

# define WIN_RATIO 0.2

# define COLOR_LIGHT_BLACK 8
# define PAIR_BORDER 100
# define PAIR_GREY 101

# define STR_WIN_TOO_SMALL "(window is too small - some lines are hidden)"
# define STR_WINNER "The winner is"
# define STR_PRESS_ANY "Press any key to finish"

typedef struct	s_vec2
{
	int		x;
	int		y;
}				t_vec2;

typedef struct	s_panel
{
	WINDOW	*win;
	t_vec2	size;
}				t_panel;

void	curses_init();
void	curses_loop(int (*cycle_fn)(t_cycle_infos *));

WINDOW	*window_create(t_vec2 size, t_vec2 pos);
void	window_destroy(WINDOW *win);

void	panel_memory_init(t_panel *panel, t_vec2 size);
void	panel_memory_draw(t_panel *panel, t_cycle_infos *cycle_infos);
void	panel_infos_init(t_panel *panel, t_vec2 size);
void	panel_infos_draw(t_panel *panel, t_cycle_infos *infos);

void	init_memory(t_cycle_infos *infos);

void	load_player_colors();

#endif
