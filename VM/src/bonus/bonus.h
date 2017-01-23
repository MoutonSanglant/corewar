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

typedef struct	s_win
{
	WINDOW	*self;
	char	*title;
	//void	*loop;
	int		x;
	int		y;
	int		h;
	int		w;
	int		color;
}				t_win;

typedef struct	s_vec2
{
	int		x;
	int		y;
}				t_vec2;

void	curses_init();
void	curses_release();

t_win	*create_window(t_vec2 coord, int starty, int startx, char *title);
void	destroy_window(t_win *win);
void	refresh_window(t_win *win);
void	swap_windows(t_win **p_win, t_vec2 row_col, t_vec2 coord, char *title);

#endif
