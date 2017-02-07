/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:50:40 by akopera           #+#    #+#             */
/*   Updated: 2017/02/07 19:48:53 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


// live_exec:
// ft_printf(STR_LIVE_EXEC, champ->id, champ->name);

static void		run()
{
	int		winner_id;

	winner_id = 0;
	g_corewar.cycle_infos.cycle_to_die = CYCLE_TO_DIE;
	g_corewar.cycle_infos.checks_count = 0;
	ft_printf("DDD\n");
	cycle_handler();
	ft_printf(STR_PLAYER_WIN, winner_id, NULL);
}

void			run_vm()
{
	char	arena[MEM_SIZE];
	int		i;

	g_corewar.cycle_infos.arena = arena;
	// initialisation
	// step 1: initialiser la mémoire à 0
	ft_bzero(arena, MEM_SIZE);

	i = 0;
	while (i < g_corewar.player_count)
	{
		// créé le processus
		//g_corewar.players[i].champ_proc = process_create(0);
		g_corewar.process = process_create(0);
		// initialise le processus à 0
		//ft_bzero(&players[i].champ_proc, sizeof(t_proc));
		// initialise tous les registres à 0
		//ft_bzero(&players[i].champ_proc->reg, sizeof(t_registry) * REG_NUMBER);
		// initialiser r1 (le registre 0) au numéro du player
		//i++;
		set_reg(g_corewar.process[i].reg[0], (char *)&g_corewar.players[i].number, sizeof(int));
		//i--;
		i++;
	}
	i = g_corewar.player_count;
	while (--i >= 0)
	{
		g_corewar.players[i].champ_proc = &g_corewar.process[i];
	}
	// step 3: copier les codes en memoire
	load_players_in_mem(arena, g_corewar.players);
	run();

	// TODO
	// deplacer dans une fonction 'post traitement'
	// qui est execute APRES la liberation de ncurses



/*
	int j;			//DEBUG & TESTS

	j = 0;
	players->next_op = players->bytecode;
	while (players->next_op[0])
	{
		parse_bytecode(players);
	}
*/
}
