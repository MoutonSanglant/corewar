/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:28:06 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/23 20:19:02 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	destroy_window(t_win *win)
{
	//wborder(win->self, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wborder(win->self, '.', '-', '+', '*', ',', '|', '\\', '/');
	wrefresh(win->self);
	delwin(win->self);
	ft_memdel((void **)&win);
}
