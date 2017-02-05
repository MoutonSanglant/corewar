/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:11:11 by akopera           #+#    #+#             */
/*   Updated: 2017/02/05 21:16:49 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"

void	load_players_in_mem(int players_nb, char *terrain, t_player *players)
{
	int i;
	int champ_start_pos;

	i = 0;
	champ_start_pos = 0;
	while (i < players_nb)
	{
		champ_start_pos = MEM_SIZE / players_nb * i;
		ft_memcpy(&terrain[champ_start_pos], players[i].bytecode, players[i].prog_size);
		players[i].champ_proc->pc = &terrain[champ_start_pos];
		i++;
	}

}
