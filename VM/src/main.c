/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:27:30 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/26 00:21:35 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_corewar	g_corewar;

int		main(int ac, char **av)
{
	t_flags		flags;
	//t_player	*players;				// liste de joueurs
	//int			players_count;			// le nombre de champs en jeu
										// a definir dans parse_arg || read_binary ?

	ft_bzero(&g_corewar, sizeof(t_corewar));
	if (ac < 2)
		error(ERRNO_USAGE, NULL);
	parse_arguments(ac - 1, &av[1], &flags);
	//ft_printf("flag: %x\n", flags);
	//return (0);
	//players_count = ac - 1;
	//ft_printf("players count: %i\n", players_count);

	init();
	run_vm(g_corewar.player_count, g_corewar.players);
	release();
	return (0);
}
