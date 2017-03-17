/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:22:00 by akopera           #+#    #+#             */
/*   Updated: 2017/03/17 17:03:30 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


void		live_op(t_proc *proc, t_op_arg args[3])
{
	t_cycle_infos	*infos;
	t_player		*player;

	infos = &g_corewar.cycle_infos;
	proc->live++;
	if ((player = find_player(args[0].value)))
	{
//		mark_byte(proc->pc);
		infos->byte_infos[proc->pc - infos->arena].live = 50;
		infos->last_live = player->number;
		player->last_live = infos->count;
		player->current_lives++;
	}
}
