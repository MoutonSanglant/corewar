/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:07:54 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/21 10:25:05 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	mark_bytes(t_cycle_infos *infos)
{
	t_proc	*process;
	int		offset;
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		infos->byte_infos[i].pc = 0;
		i++;
	}
	i = 0;
	while (i < g_corewar.process_count)
	{
		process = &g_corewar.process[i];
		offset = process->pc - infos->arena;
		infos->byte_infos[offset].pc |= 1;
		i++;
	}
}
