/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:11:11 by akopera           #+#    #+#             */
/*   Updated: 2017/02/14 21:43:30 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	load_players_in_mem(char *terrain, t_player *players)
{
	int i;
	int champ_start_pos;

	i = 0;
	champ_start_pos = 0;
	while (i < g_corewar.player_count)
	{
		champ_start_pos = MEM_SIZE / g_corewar.player_count * i;
		ft_memcpy(&terrain[champ_start_pos], players[i].bytecode, players[i].prog_size);
		//players[i].champ_proc->pc = &terrain[champ_start_pos];
		g_corewar.process[i].pc = &terrain[champ_start_pos];
		i++;
	}

}

t_player	*find_player(int id)
{
	t_player	*player;
	int			i;

	i = 0;
	while (i < g_corewar.player_count)
	{
		player = &g_corewar.players[i];
		if (player->number == id)
			return (player);
		i++;
	}
	return (NULL);
}
