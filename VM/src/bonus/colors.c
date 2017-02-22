/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:33:28 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/22 16:22:09 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	load_player_colors(void)
{
	static int	pairs[8][2] = {
		{ COLOR_GREEN, COLOR_BLACK },
		{ COLOR_RED, COLOR_BLACK },
		{ COLOR_YELLOW, COLOR_BLACK },
		{ COLOR_CYAN, COLOR_BLACK },
		{ COLOR_WHITE, COLOR_GREEN },
		{ COLOR_WHITE, COLOR_RED },
		{ COLOR_WHITE, COLOR_YELLOW },
		{ COLOR_WHITE, COLOR_CYAN }
	};
	t_player	*player;
	int			i;

	i = 0;
	while (i < g_corewar.player_count)
	{
		player = &g_corewar.players[i];
		init_pair(player->id, pairs[i][0], pairs[i][1]);
		init_pair(player->id + 4, pairs[i + 4][0], pairs[i + 4][1]);
		i++;
	}
}
