/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:34:51 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/22 15:58:34 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "bonus/bonus.h"

void		run_processes(void)
{
	t_proc	*process;
	int		opcode;
	int		offset;
	int		i;

	i = g_corewar.process_count - 1;
	while (i >= 0)
	{
		process = &g_corewar.process[i];
		opcode = (int)process->pc[0];
		if (opcode <= 16 && opcode > 0)
		{
			if (!process->op)
				process->op = &g_op_tab[opcode - 1];
			if (++process->wait >= process->op->cycles)
			{
				process->wait = 0;
				offset = process_op(process);
				process_move(&g_corewar.process[i], offset);
			}
		}
		else
			process_move(process, 1);
		i--;
	}
}

static int	check_process_live_msg(t_cycle_infos *infos)
{
	t_proc		*process;
	int			count;
	int			i;

	i = g_corewar.process_count - 1;
	count = 0;
	while (i >= 0)
	{
		process = &g_corewar.process[i];
		if (process->live)
		{
			count += process->live;
			process->live = 0;
		}
		else
			process_kill(g_corewar.process, i);
		i--;
	}
	i = 0;
	while (i < g_corewar.player_count)
		g_corewar.players[i++].current_lives = 0;
	infos->nbr_live = count;
	return (count >= NBR_LIVE);
}

static int	cycle(t_cycle_infos *infos)
{
	t_player	*winner;

	if (infos->count >= (unsigned int)g_corewar.dump_cycle)
		dump_memory(infos->arena);
	if (infos->cycle_to_die <= 0)
	{
		if ((winner = find_player(infos->last_live)))
			infos->winner = winner;
		return (0);
	}
	run_processes();
	infos->running_proc = g_corewar.process_count;
	if ((infos->count % infos->cycle_to_die) == 0 && infos->count > 0)
	{
		infos->checks_count++;
		if (check_process_live_msg(infos))
		{
			infos->checks_count = 0;
			infos->cycle_to_die -= CYCLE_DELTA;
		}
	}
	if (infos->checks_count >= MAX_CHECKS)
	{
		infos->checks_count = 0;
		infos->cycle_to_die -= CYCLE_DELTA;
	}
	if (infos->running_proc <= 0)
	{
		if ((winner = find_player(infos->last_live)))
			infos->winner = winner;
		return (0);
	}
	infos->count++;
	return (1);
}

#ifdef BONUS

void		cycle_handler(void)
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

void		cycle_handler(void)
{
	while (cycle(&g_corewar.cycle_infos))
		;
}

#endif
