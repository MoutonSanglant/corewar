/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:34:51 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/16 18:13:42 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "bonus/bonus.h"

static void	run_processes(void)
{
	t_proc	*process;
	int		opcode;
	int		offset;
	int		i;

	i = g_corewar.process_count - 1;
	while (i >= 0)
	{
		process = &g_corewar.process[i];
		if (process->wait < 0)
		{
			opcode = (int)read_byte(process->pc) - 1;
			if (opcode < OP_COUNT && opcode >= 0)
			{
				process->start_op = &g_op_tab[opcode];
				process->ocp = read_byte(process->pc + 1);
				process->wait = g_op_tab[opcode].cycles;
			}
			else
			{
				process_move(&g_corewar.process[i], 1);
				i--;
				continue ;
			}
		}
		if (--process->wait <= 0)
		{
			offset = process_op(process);
			process_move(&g_corewar.process[i], offset);
		}
		i--;
	}
}

static int	check_process_live_msg(t_cycle_infos *infos)
{
	t_proc		*process;
	size_t		live_count;
	size_t		die_count;
	int			i;

	i = g_corewar.process_count - 1;
	live_count = 0;
	die_count = 0;
	while (i >= 0)
	{
		process = &g_corewar.process[i];
		if (process->live)
			live_count += process->live;
		else
			die_count++;
		i--;
	}
	if (die_count > 0)
		kill_processes(g_corewar.process_count - die_count);
	else
	{
		i = g_corewar.process_count - 1;
		while (i >= 0)
			g_corewar.process[i--].live = 0;
	}
	i = 0;
	while (i < g_corewar.player_count)
		g_corewar.players[i++].current_lives = 0;
	infos->nbr_live = live_count;
	return (live_count >= NBR_LIVE);
}

static int	cycle(t_cycle_infos *infos)
{
	if (infos->count >= (unsigned int)g_corewar.dump_cycle)
		dump_memory(infos->arena);
	infos->count++;
	run_processes();
	if (infos->count >= infos->check_cycle)
	{
		infos->checks_count += (check_process_live_msg(infos)) ? MAX_CHECKS : 1;
		infos->check_cycle = infos->count + infos->cycle_to_die;
	}
	infos->running_proc = g_corewar.process_count;
	if (infos->checks_count >= MAX_CHECKS)
	{
		infos->checks_count = 0;
		infos->cycle_to_die -= CYCLE_DELTA;
		infos->check_cycle -= CYCLE_DELTA;
	}
	if (infos->running_proc <= 0 || infos->cycle_to_die <= 0)
		return (0);
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
