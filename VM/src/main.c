/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:27:30 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/06 23:24:24 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_corewar	g_corewar;

int		main(int ac, char **av)
{
	ft_bzero(&g_corewar, sizeof(t_corewar));
	if (ac < 2)
		error(ERRNO_USAGE, NULL);
	parse_arguments(ac - 1, &av[1], &g_corewar.flags);
	run_vm(g_corewar.player_count);
	return (0);
}
