/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 02:03:15 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/14 21:32:42 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	write_bytes(char *dst, char *src, size_t count, int number)
{
	t_byte_infos	*byte;
	t_player		*player;
	size_t			offset;
	size_t			i;

	i = 0;
	offset = 0;
	if (dst != g_corewar.cycle_infos.arena)
		offset = dst - g_corewar.cycle_infos.arena;
	while (i < count)
	{
		dst[i] = src[i];
		byte = &g_corewar.cycle_infos.byte_infos[offset + i];
		byte->op = 50;
		if ((player = find_player(number)))
			byte->number = player->id;
		i++;
	}
}

void	read_range(char *dst, char *pc, size_t range)
{
	char	*mem;
	int		overflow;

	if ((mem = g_corewar.cycle_infos.arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	else if (pc > mem + MEM_SIZE)
		pc = mem + (pc - (mem + MEM_SIZE)) % MEM_SIZE;
	if ((overflow = pc + range - (mem + MEM_SIZE)) > 0)
	{
		range -= overflow;
		ft_memcpy((void *)&dst[range], (void *)mem, overflow);
	}
	ft_memcpy((void *)dst, (void *)pc, range);
}

void	write_range(char *src, char *pc, size_t range, int number)
{
	char	*mem;
	int		overflow;

	// arena commence à 0,
	// termine à MEM_SIZE - 1
	//
	// si pc < arena
	// --> on le replace dedans
	if ((mem = g_corewar.cycle_infos.arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	// si pc > arena
	// --> on le replace dedans !
	else if (pc > mem + MEM_SIZE)
		pc = mem + (pc - (mem + MEM_SIZE)) % MEM_SIZE;
	// si pc + range > arena
	// --> on écrit à partir du début de l'arena
	if ((overflow = pc + range - (mem + MEM_SIZE)) > 0)
	{
		range -= overflow;
		write_bytes(mem, &src[range], overflow, number);
	}
	// on écrit le reste à partir du pc
	write_bytes(pc, src, range, number);
}


char	*get_addr(char *addr)
{
	int		overflow;

	if ((overflow = addr - (g_corewar.cycle_infos.arena + MEM_SIZE)) >= 0)
		return (&g_corewar.cycle_infos.arena[overflow]);
	return (addr);
}

char	read_byte(char *addr)
{
	int		overflow;

	if ((overflow = addr - (g_corewar.cycle_infos.arena + MEM_SIZE)) >= 0)
		return (g_corewar.cycle_infos.arena[overflow]);
	return (*addr);
}
