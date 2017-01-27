/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:50:40 by akopera           #+#    #+#             */
/*   Updated: 2017/01/27 19:06:04 by tdefresn         ###   ########.fr       */
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

// live_exec:
// ft_printf(STR_LIVE_EXEC, champ->id, champ->name);

static void		run()
{
	int		winner_id;

	winner_id = 0;
	g_corewar.cycle_infos.cycle_to_die = CYCLE_TO_DIE;
	g_corewar.cycle_infos.checks_count = 0;
	cycle_handler();
	ft_printf(STR_PLAYER_WIN, winner_id, NULL);
}

void			run_vm(int players_count, t_player *players)
{
	char		*terrain;

	terrain = (char*)malloc(sizeof(char) * MEM_SIZE);
	ft_bzero(terrain, MEM_SIZE);
//	dump_memory(terrain);
	load_players_in_mem(players_count, terrain, players);
	while (players_count)
	{
		set_players_regs(&players[players_count - 1]);
		players_count--;
	}

	// step 3: copier les codes en memoire
	load_players_in_mem(players_count, arena, players);

	run();
	// TODO
	// deplacer dans une fonction 'post traitement'
	// qui est execute APRES la liberation de ncurses
	dump_memory(terrain);
}
