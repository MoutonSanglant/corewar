/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:34:51 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/05 19:06:32 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "bonus/bonus.h"

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

static int		check_process_live_msg()
{
	return (0);
}

static int		cycle(t_cycle_infos *infos, t_player *players)
{
	if (infos->cycle_to_die <= 0)
		return (0);
	run_processes(infos, players);
	if ((infos->count % infos->cycle_to_die) == 0)
		check_process_live_msg();
	if (infos->checks_count >= MAX_CHECKS)
	{
		infos->checks_count = 0;
		infos->cycle_to_die--;
	}
	// if at last NBR_LIVE exec of live since last check, then CYCLE_TO_DIE -= CYCLE_ALPHA
	//	if (!infos->process_live_count)
	//		return (0);
	infos->count++;
	return (1);
}

#ifdef BONUS

void	cycle_handler(t_player *players)
{
	if (g_corewar.flags & FLAG_NCUR)
	{
		curses_init();
		curses_loop(&cycle, players);
	}
	else
	{
		while (cycle(&g_corewar.cycle_infos, players) && g_corewar.cycle_infos.count < 20000)
			;
	}
}

#else

void	cycle_handler(t_player *players)
{
	while (cycle(&g_corewar.cycle_infos, players) && g_corewar.cycle_infos.count < 20000)
		;
}

#endif
