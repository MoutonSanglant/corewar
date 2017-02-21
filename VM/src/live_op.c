/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:22:00 by akopera           #+#    #+#             */
/*   Updated: 2017/02/21 19:17:01 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	mark_byte(char *pc)
{
	int			offset;

	offset = pc - g_corewar.cycle_infos.arena;
	//ft_printf("pc: %p\nar: %p\n", pc, g_corewar.cycle_infos.arena);
	//ft_printf("offset: %i\n", offset);
	g_corewar.cycle_infos.byte_infos[offset].live = 50;
}

void	live_op(t_proc *proc, t_op_arg args[3])
{
	t_player	*player;

	player = NULL;
	proc->live++;
	if ((player = find_player(args[0].value)))
	{
		mark_byte(proc->pc);
		g_corewar.cycle_infos.last_live = player->number;
		player->last_live = g_corewar.cycle_infos.count + 1;
		player->current_lives++;
	}
}
