/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:04:02 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/23 09:06:39 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	draw(t_panel panels[2], t_cycle_infos *infos)
{
	mark_bytes(&g_corewar.cycle_infos);
	panel_memory_draw(&panels[0], infos);
	panel_infos_draw(&panels[1], infos);
	wrefresh(panels[0].win);
	wrefresh(panels[1].win);
}
