/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:11:11 by akopera           #+#    #+#             */
/*   Updated: 2017/01/23 18:13:01 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"

void	set_players_regs(t_player *players)
{
	int	j;
	int k;

	j = 1;
	k = 0;
	// TODO:
	// remplacer par ft_memalloc ou ajouter bzero
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
