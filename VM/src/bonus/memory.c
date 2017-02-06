/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:41:56 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/06 16:42:19 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	init_player_memory(t_cycle_infos *infos, t_player *player)
{
	int		start;
	int		i;

	start = player->champ_proc->pc - infos->arena;
	i = start + player->prog_size;
	while (i >= start)
	{
		infos->byte_infos[i].number = player->number + 1;
		i--;
	}
}

void		init_memory(t_cycle_infos *infos, t_player *players)
{
	int			i;

	i = 0;
	ft_bzero(&infos->byte_infos, MEM_SIZE);
	while (i < g_corewar.player_count)
	{
		init_player_memory(infos, &players[i]);
		i++;
	}
}
