/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:34:51 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/06 23:21:22 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "bonus/bonus.h"

/*
TODO: remplacer par logique:
		si le process arrive au cycle N -> run

int			check_idle(t_player *player, int idle_time)
{
	if (player->idle != 1)
	{
		if (player->idle < 0)
			player->idle += idle_time;
		else
			player->idle--;
		return (0);
	}
	ft_printf("Cycle : %d ", g_corewar.cycle_infos.count);
	return (1);
}
*/

static int		check_process_live_msg()
{
	return (1);
}

static int		cycle(t_cycle_infos *infos)
{
	int	i;

	if (infos->count > 20000 || infos->cycle_to_die <= 0)
		return (0);
	//run_processes(infos, players);
	i = g_corewar.process_count - 1;
	while(i >= 0)
	{
		// SI process.cycle = 0 -> run
		// parse_bytecode -> run_process
		parse_bytecode(&g_corewar.process[i]);
		i--;
	}
	if ((infos->count % infos->cycle_to_die) == 0 && infos->count > 0)
	{
		// if there is at least 1 live...
		if (check_process_live_msg())
			infos->cycle_to_die -= CYCLE_DELTA;
	}
	if (infos->checks_count >= MAX_CHECKS)
	{
		infos->checks_count = 0;
		infos->cycle_to_die--;
	}
	//	if (!infos->process_live_count)
	//		return (0);
	infos->count++;
	return (1);
}

#ifdef BONUS

void	cycle_handler()
{
	if (g_corewar.flags & FLAG_NCUR)
	{
		curses_init();
		curses_loop(&cycle);
	}
	else
	{
		while (cycle(&g_corewar.cycle_infos))
			;
	}
}

#else

void	cycle_handler()
{
	while (cycle(&g_corewar.cycle_infos))
		;
}

#endif
