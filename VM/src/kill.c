/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:23:32 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/28 18:23:41 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	kill_processes(size_t count)
{
	t_proc	*process;
	t_proc	*tmp;
	int		from_idx;
	size_t	idx;
	size_t	i;

	tmp = g_corewar.process;
	if (!(g_corewar.process = (t_proc *)malloc(sizeof(t_proc) * count)))
		error(ERRNO_MEMORY, "process kill");
	i = 0;
	idx = 0;
	from_idx = -1;
	while (i < (size_t)(g_corewar.process_count))
	{
		process = &tmp[i];
		if (process->live)
		{
			process->live = 0;
			if (from_idx < 0)
				from_idx = i;
		}
		else if (from_idx >= 0)
		{
			ft_memcpy(&g_corewar.process[idx], &tmp[from_idx],
											sizeof(t_proc) * (i - from_idx));
			idx += i - from_idx;
			from_idx = -1;
		}
		i++;
	}
	if (from_idx >= 0)
	{
		ft_memcpy(&g_corewar.process[idx], &tmp[from_idx],
											sizeof(t_proc) * (i - from_idx));
	}
	free(tmp);
	g_corewar.process_count = count;
}
