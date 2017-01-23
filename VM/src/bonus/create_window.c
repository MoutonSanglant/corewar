/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:55:58 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/23 20:41:50 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

t_win	*create_window(t_vec2 coord, int starty, int startx, char *title)
{
	t_win *win;

	win = (t_win *)malloc(sizeof(t_win));
	win->self = newwin(coord.y, coord.x, starty, startx);
	box(win->self, 0, 0);
	wrefresh(win->self);
	(void)title;
	/*
	win->w = coord.x;
	win->h = coord.y;
	win->x = startx;
	win->y = starty;
	win->title = ft_strdup(title);
	//win->caption = NULL;
	refresh_window(win);
	*/
	return (win);
}
