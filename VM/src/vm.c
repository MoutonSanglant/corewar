/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:50:40 by akopera           #+#    #+#             */
/*   Updated: 2017/01/27 18:56:44 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		dump_memory(char *terrain)
{
	int	i;
	int j;
	int k;
	char *octet;


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
		octet = ft_itoa_base((intmax_t)terrain[i], 16);

		if (ft_strlen(octet) == 1)
		{
			ft_printf("0", octet);
			ft_printf("%s ", octet);
		}
		else if (ft_strlen(octet) > 2)
		{
			ft_printf("%c", octet[ft_strlen(octet) - 2]);
			ft_printf("%c ", octet[ft_strlen(octet) - 1]);
		}
		else
			ft_printf("%s ", octet);
		i++;
		j++;
	}
	ft_printf("\n");
}

static int		check_process_live_msg()
{
	return (0);
}

// live_exec:
// ft_printf(STR_LIVE_EXEC, champ->id, champ->name);

static int		cycle(int n, int *cycle_to_die)
{
	static int	s_checks_count = 0;
	int		process_live_count;
	int		last_alive_process;

	last_alive_process = 0;
	(void)last_alive_process;
	process_live_count = 0;
	if ((n % *cycle_to_die) == 0)
		check_process_live_msg();
	if (s_checks_count >= MAX_CHECKS)
	{
		s_checks_count = 0;
		(*cycle_to_die)--;
	}
	// if at last NBR_LIVE exec of live since last check, then CYCLE_TO_DIE -= CYCLE_ALPHA
	if (!process_live_count)
		return (0);
	return (1);
}

static	void	do_op(t_player *player)
{
	parse_bytecode(player);
}

static void		run(t_player *players, int players_count)
{
	int		i;
	int		j;
	int		cycle_to_die;
	int		winner_id;

	i = 0;
	j = players_count - 1;
	cycle_to_die = CYCLE_TO_DIE;
	winner_id = 0;
	while (cycle(i++, &cycle_to_die))
	{
		while (j >= 0)
		{
			do_op(&players[j]);
			j--;
		}
		j = players_count - 1;
	}

	ft_printf(STR_PLAYER_WIN, winner_id, NULL);
}

void			run_vm(int players_count, t_player *players)
{
	char	arena[MEM_SIZE];
	int		i;


	// initialisation
	// step 1: initialiser la mémoire à 0
	ft_bzero(arena, MEM_SIZE);

	i = players_count;
	// step 2: initialiser les processus (registres, pc, carry)
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
	run(players, players_count);
	// TODO
	// deplacer dans une fonction 'post traitement'
	// qui est execute APRES la liberation de ncurses


	dump_memory(arena);


	int j;			//DEBUG & TESTS

	j = 0;
	players->next_op = players->bytecode;
	ft_printf("OPCODE ENCORE AVANT : %d\n", (int)players->bytecode[0]);
	while (players->next_op[0])
	{
		parse_bytecode(players);
	}


}
