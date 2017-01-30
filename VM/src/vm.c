/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:50:40 by akopera           #+#    #+#             */
/*   Updated: 2017/01/30 19:28:14 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		dump_memory(char *terrain)
{
	int	i;
	int j;
	int k;


	i = 0;
	j = 0;
	k = 0;
	while (i < MEM_SIZE)
	{
		if (j == 64)
		{
			ft_printf("\n");
			j = 0;
			k++;
		}
		if (j == 0)
			ft_printf("%#.4p : ", k * 64);
		ft_printf("%.2x ", terrain[i] & 0xff);

		i++;
		j++;
	}
	ft_printf("\n");
}

// live_exec:
// ft_printf(STR_LIVE_EXEC, champ->id, champ->name);

static void		run(t_player *players)
{
	int		winner_id;

	winner_id = 0;
	g_corewar.cycle_infos.cycle_to_die = CYCLE_TO_DIE;
	g_corewar.cycle_infos.checks_count = 0;
	cycle_handler(players);
	ft_printf(STR_PLAYER_WIN, winner_id, NULL);
}

void			run_vm(int players_count, t_player *players)
{
	char	arena[MEM_SIZE];
	int		i;

	g_corewar.cycle_infos.arena = arena;
	// initialisation
	// step 1: initialiser la mémoire à 0
	ft_bzero(arena, MEM_SIZE);

	i = players_count;
	while (--i >= 0)
	{
		// initialise le processus à 0
		ft_bzero(&players[i].champ_proc, sizeof(t_proc));
		// initialise tous les registres à 0
		ft_bzero(&players[i].champ_proc.reg, sizeof(t_registry) * REG_NUMBER);
		// initialiser r1 (le registre 0) au numéro du player
		i++;
		set_reg(players[i].champ_proc.reg[0], (char *)&i, sizeof(int));
		i--;
	}
	// step 3: copier les codes en memoire
	load_players_in_mem(players_count, arena, players);
	dump_memory(arena);
	ft_printf("PLAYER[0] idle : %d\n", players[0].idle);
	run(players);

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
