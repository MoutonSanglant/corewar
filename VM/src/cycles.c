/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:34:51 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/14 21:41:41 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "bonus/bonus.h"

void		run_processes()
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
			if (process->wait++ >= op->cycles)
			{
				process->wait = 0;
				offset = process_op(process, op);
				//ft_printf("[DEBUG] \033[3%improcess %i\033[0m\n", i + 1, i);
				//ft_printf("[DEBUG] from @%x\n", g_corewar.process[i].pc);
				process_move(&g_corewar.process[i], offset);
				//ft_printf("[DEBUG] to   @%x\n", g_corewar.process[i].pc);
				//ft_printf("[DEBUG] offset: %u\n", offset);
			}
		}
		else
		{
			// opcode inconnu,
			// on avance le pc de 1
			//ft_printf("[DEBUG] process %i move 1 byte\n", i);
			process_move(process, 1);
		}
		i--;
	}
}

static int		check_process_live_msg(t_cycle_infos *infos)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (i < g_corewar.process_count)
	{
		if (g_corewar.process[i].live)
		{
			g_corewar.process[i].live = 0;
			count++;
		}
		else
			process_kill(g_corewar.process, i);
		i++;
	}
	infos->nbr_live = count;
	return ((count >= NBR_LIVE));
}

static int		cycle(t_cycle_infos *infos)
{
	if (infos->count >= (unsigned int)g_corewar.dump_cycle)
		dump_memory(infos->arena);
	if (infos->count > 25000 || infos->cycle_to_die <= 0)
	{
		infos->winner = find_player(infos->last_live);
		return (0);
	}
	//ft_printf("cycle: %i\n", infos->count);
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
		if (infos->running_proc <= 0)
		{
			infos->winner = find_player(infos->last_live);
			return (0);
		}
	}
	if (infos->checks_count >= MAX_CHECKS)
	{
		infos->checks_count = 0;
		infos->cycle_to_die -= CYCLE_DELTA;
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
