/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:13:49 by akopera           #+#    #+#             */
/*   Updated: 2017/01/30 19:55:44 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	run_processes(t_cycle_infos *infos, t_player *players)
{
	int	i;

	(void)infos; //TODO remove
	i = g_corewar.player_count - 1;
	while(i >= 0)
	{
		parse_bytecode(&players[i]);
		i--;
	}
}
