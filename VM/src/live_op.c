/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:22:00 by akopera           #+#    #+#             */
/*   Updated: 2017/02/20 22:56:48 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live_op(t_proc *proc, t_op_arg args[3])
{
	t_player	*player;

	player = NULL;
	proc->live++;
	if ((player = find_player(args[0].value)))
	{
		g_corewar.cycle_infos.last_live = player->number;
		player->last_live = g_corewar.cycle_infos.count;
		player->current_lives++;
	}
}
