/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:33:28 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/06 18:51:34 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	load_player_colors()
{
	static int	pairs[4][2] = {
		{ COLOR_GREEN, COLOR_BLACK },
		{ COLOR_RED, COLOR_BLACK },
		{ COLOR_YELLOW, COLOR_BLACK },
		{ COLOR_BLUE, COLOR_BLACK }
	};
	int			i;

	i = 0;
	while (i < g_corewar.player_count)
	{
		init_pair(g_corewar.players[i].number, pairs[i][0], pairs[i][1]);
		i++;
	}
}


