/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:22:00 by akopera           #+#    #+#             */
/*   Updated: 2017/03/17 17:29:55 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		live_op(t_proc *proc, t_op_arg args[3])
{
	t_cycle_infos	*infos;
	t_player		*player;
	int				offset;

	proc->live++;
	if ((player = find_player(args[0].value)))
	{
		infos = &g_corewar.cycle_infos;
		offset = proc->pc - infos->arena;
		if (offset >= 0 && offset < MEM_SIZE)
			infos->byte_infos[offset].live = 50;
		infos->last_live = player->number;
		player->last_live = infos->count;
		player->current_lives++;
	}
}
