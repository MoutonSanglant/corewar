/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 08:19:14 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/23 08:19:41 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	wprint_buf(WINDOW *win, t_vec2 *pos, int width, char *buf)
{
	wmove(win, pos->y, pos->x);
	waddnstr(win, buf, width);
	pos->y += 1;
}
