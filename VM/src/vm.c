/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:50:40 by akopera           #+#    #+#             */
/*   Updated: 2017/02/14 20:59:11 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		run()
{
	int		winner_id;

	winner_id = 0;
	g_corewar.cycle_infos.running_proc = g_corewar.process_count;
	g_corewar.cycle_infos.cycle_to_die = CYCLE_TO_DIE;
	g_corewar.cycle_infos.checks_count = 0;
	cycle_handler();
	ft_printf(STR_PLAYER_WIN, winner_id, NULL);
}

void			run_vm()
{
	char		arena[MEM_SIZE];
	t_player	*player;
	int			i;

	// initialisation
	g_corewar.cycle_infos.arena = arena;
	ft_bzero(arena, MEM_SIZE);
	i = 0;
	while (i < g_corewar.player_count)
	{
		player = &g_corewar.players[i];
		ft_printf(STR_PLAYER_SUM, (int)player->number, player->prog_size,
											player->name, player->comment);
		// création du processus
		process_create(0);
		// initialisation de r1 (au numéro du player)
		swap_endianess((char *)g_corewar.process[i].reg, (char *)&player->number, sizeof(int));
		i++;
	}
	// copie des programmes dans la memoire
	load_players_in_mem(arena, g_corewar.players);
	// exécurtion
	run();
}
