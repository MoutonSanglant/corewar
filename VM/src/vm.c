/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:50:40 by akopera           #+#    #+#             */
/*   Updated: 2017/01/23 20:19:42 by akopera          ###   ########.fr       */
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
	dump_memory(terrain);
}
