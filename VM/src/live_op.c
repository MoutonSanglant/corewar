/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:22:00 by akopera           #+#    #+#             */
/*   Updated: 2017/02/16 19:06:06 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live_op(t_proc *proc, t_op_arg args[3])
{
	t_player	*player;

	player = NULL;
	//ft_printf("live \n");
	proc->live = args[0].value;
	if ((player = find_player(args[0].value)))
	{
		player->last_live = g_corewar.cycle_infos.count;
		player->current_lives++;
	}
}
