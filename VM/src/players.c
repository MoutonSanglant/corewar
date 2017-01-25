/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:11:11 by akopera           #+#    #+#             */
/*   Updated: 2017/01/24 18:38:58 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"

/*
void	set_players_regs(t_player *players)
{
	int	j;
	int k;

	j = 1;
	k = 0;
	players->champ_proc = (t_proc*)malloc(sizeof(t_proc));
	players->champ_proc->reg[0][0] = players->number;	//reg[0][REG_SIZE -1]?
	while (j < REG_NUMBER)
	{
		while (k < REG_SIZE)
		{
			players->champ_proc->reg[j][k] = 0;
			k++;
		}
		k = 0;
		j++;
	}
	j = 1;
}
*/

void	load_players_in_mem(int players_nb, char terrain[MEM_SIZE], t_player *players)
{
	int i;
	int champ_start_pos;

	i = 0;
	champ_start_pos = 0;
	while (i < players_nb)
	{
		champ_start_pos = MEM_SIZE / players_nb * i;
		ft_memcpy(&terrain[champ_start_pos], players[i].bytecode, players[i].prog_size);
		i++;
	}

}
