/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:34:51 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/17 20:28:15 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "bonus/bonus.h"

void		run_processes(void)
{
	t_proc	*process;
	t_op	*op;
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
			op = &g_op_tab[opcode - 1];
			if (++process->wait >= op->cycles)
			{
				process->wait = 0;
				offset = process_op(process, op);
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
	int		count;
	int		i;

	i = g_corewar.process_count - 1;
	count = 0;
	while (i >= 0)
	{
		if (g_corewar.process[i].live)
		{
			g_corewar.process[i].live = 0;
			count++;
		}
		else
			process_kill(g_corewar.process, i);
		i--;
	}
	i = 0;
	while (i < g_corewar.player_count)
	{
		g_corewar.players[i].current_lives = 0;
		i++;
	}
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
		winner = find_player(infos->last_live);
		if (winner)
			infos->winner = winner;
		return (0);
	}
	run_processes();
	if ((infos->count % infos->cycle_to_die) == 0 && infos->count > 0)
	{
		infos->checks_count++;
		// if there is at least 1 live...
		if (check_process_live_msg(infos))
		{
			infos->checks_count = 0;
			infos->cycle_to_die -= CYCLE_DELTA;
		}
		infos->running_proc = g_corewar.process_count;
	}
	if (infos->checks_count >= MAX_CHECKS)
	{
		infos->checks_count = 0;
		infos->cycle_to_die -= CYCLE_DELTA;
	}
	if (infos->running_proc <= 0)
	{
		winner = find_player(infos->last_live);
		if (winner)
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
