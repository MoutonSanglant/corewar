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

# define WIN_RATIO 0.2

# define COLOR_LIGHT_BLACK 8

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
//void	curses_release();

WINDOW	*window_create(t_vec2 size, t_vec2 pos);
void	window_destroy(WINDOW *win);

void	panel_memory_init(t_panel *panel, t_vec2 size);
void	panel_memory_draw(t_panel *panel, t_cycle_infos *cycle_infos);
void	panel_infos_init(t_panel *panel, t_vec2 size);
void	panel_infos_draw(t_panel *panel, t_cycle_infos *cycle_infos);
//void	window_refresh(t_win *win);
//void	window_resize();

#endif
