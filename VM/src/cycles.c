/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:34:51 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/27 19:26:37 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "bonus/bonus.h"

static int		check_process_live_msg()
{
	return (0);
}

static int		cycle(t_cycle_infos *infos)
{
	if (infos->cycle_to_die <= 0)
		return (0);
	infos->last_alive_process = 0;
	infos->process_live_count = 0;
	if ((infos->count % infos->cycle_to_die) == 0)
		check_process_live_msg();
	if (infos->checks_count >= MAX_CHECKS)
	{
		infos->checks_count = 0;
		infos->cycle_to_die--;
	}
	// if at last NBR_LIVE exec of live since last check, then CYCLE_TO_DIE -= CYCLE_ALPHA
	if (!infos->process_live_count)
		return (0);
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
