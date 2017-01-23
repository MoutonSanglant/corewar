/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:27:30 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/23 20:46:22 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_corewar	g_corewar;

int		main(int ac, char **av)
{
	t_flags		flags;
	t_player	*players;				// liste de joueurs
	int			players_count;			// le nombre de champs en jeu
										// a definir dans parse_arg || read_binary ?

	ft_bzero(&g_corewar, sizeof(t_corewar));
	if (ac < 2)
		error(ERRNO_USAGE, NULL);
	ac -= parse_arguments(ac, &av[1], &flags);
	init();
	players_count = ac - 1;
	read_champions(players_count, &av[1]);

	players = g_corewar.players;
	ft_printf("L: %i\n", players[0].prog_size);
	run_vm(players_count, players);
	release();
	return (0);
}
