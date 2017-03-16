/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:07:54 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/16 08:55:33 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	mark_bytes(t_cycle_infos *infos)
{
	t_byte_infos	*byte;
	t_proc			*process;
	int				offset;
	int				i;

	i = 0;
	while (i < MEM_SIZE)
	{
		byte = &infos->byte_infos[i];
		byte->pc = 0;
		if (g_corewar.state == STATE_RUNNING)
		{
			if (byte->live > 0)
				byte->live--;
			if (byte->op > 0)
				byte->op--;
		}
		i++;
	}
	i = 0;
	while (i < g_corewar.process_count)
	{
		process = &g_corewar.process[i];
		if (process->pc >= infos->arena + MEM_SIZE)
			offset = 0;
		else
			offset = process->pc - infos->arena;
		infos->byte_infos[offset].pc |= 1;
		i++;
	}
}
