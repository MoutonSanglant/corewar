/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:50:40 by akopera           #+#    #+#             */
/*   Updated: 2017/03/12 18:03:51 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		run(void)
{
	t_player	*winner;

	g_corewar.cycle_infos.running_proc = g_corewar.process_count;
	g_corewar.cycle_infos.cycle_to_die = CYCLE_TO_DIE;
	g_corewar.cycle_infos.check_cycle = CYCLE_TO_DIE;
	g_corewar.cycle_infos.checks_count = 0;
	g_corewar.state = STATE_PAUSED;
	g_corewar.cycle_infos.speed = 10;
	cycle_handler();
	winner = g_corewar.cycle_infos.winner;
	ft_printf(STR_PLAYER_WIN, -winner->number, winner->name);
}

void			run_vm(void)
{
	char		arena[MEM_SIZE];
	t_player	*player;
	int			i;

	if (g_corewar.player_count <= 0)
		error(ERRNO_USAGE, NULL);
	ft_printf(STR_PLAYER_INTRO);
	g_corewar.cycle_infos.arena = arena;
	ft_bzero(arena, MEM_SIZE);
	i = 0;
	while (i < g_corewar.player_count)
	{
		player = &g_corewar.players[i];
		ft_printf(STR_PLAYER_SUM, (int)player->number, player->prog_size,
			player->name, player->comment);
		process_create(0, NULL, 0);
		player->number = -player->number;
		swap_endianess((char *)&g_corewar.process[i].reg[0],
			(char *)&player->number, REG_SIZE);
		i++;
	}
	g_corewar.cycle_infos.winner = player;
	load_players_in_mem(arena, g_corewar.players);
	run();
}
