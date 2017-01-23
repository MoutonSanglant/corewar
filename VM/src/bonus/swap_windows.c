/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 19:21:15 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/23 20:00:48 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	swap_windows(t_win **p_win, t_vec2 row_col, t_vec2 coord, char *title)
{
	destroy_window(*p_win);
	*p_win = create_window(row_col, coord.y, coord.x, title);
}
