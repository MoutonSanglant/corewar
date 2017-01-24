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

# define COLOR_LIGHT_BLACK 8

typedef void (*draw_fn)();

typedef enum	e_window
{
	WIN_MEMORY = 0x1,
	WIN_INFOS = 0x2
}				t_window;

typedef struct	s_panel
{
	WINDOW	*window;
	draw_fn	draw;
	//char	*title;
	//void	*loop;
	int		y;
	int		x;
	int		h;
	int		w;
}				t_panel;

typedef struct	s_vec2
{
	int		x;
	int		y;
}				t_vec2;

void	curses_init();
//void	curses_release();

WINDOW	*window_create(t_vec2 size, t_vec2 pos);
void	window_destroy(WINDOW *win);

WINDOW	*panel_memory_init(t_vec2 size);
void	panel_memory_draw(WINDOW *win);
WINDOW	*panel_infos_init(t_vec2 size);
void	panel_infos_draw(WINDOW *win);
//void	window_refresh(t_win *win);
//void	window_resize();

#endif
