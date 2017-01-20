/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:27:30 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/20 20:45:32 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	t_flags		flags;
	t_players	*players;				// liste de joueurs
	int			nbr_players;			// le nombre de champs en jeu
										// a definir dans parse_arg || read_binary ?
	char		terrain[MEM_SIZE];

	parse_arguments(ac, av, &flags);
	if (ac != 2)
		return (error_usage());

	read_binary(av[1]);

	/*
	** Ajouts ANTO
	*/
	(void)terrain; //Juste pour compiler
	nbr_players = 4; //Juste pour compiler
	players = (t_players*)malloc(sizeof(t_players) * nbr_players);	//!!FREE!! TODO

	while (nbr_players)
	{
		set_players_regs(&players[nbr_players - 1]);
		nbr_players--;
	}
	/*
	** FIN Ajouts ANTO
	*/
	return (0);
}
