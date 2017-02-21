/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:14:49 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/21 21:45:50 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** idx sera toujours une valeur comprise entre 1 et REG_NUMBER
*/

int		read_register(t_registry *reg, int idx)
{
	int	value;

	if (idx < 1 || idx >= REG_NUMBER)
		return (0);
	swap_endianess((char *)&value, (char *)&reg[idx - 1], REG_SIZE);
	return (value);
}

static void	mark_byte(char *pc, t_registry *reg)
{
	t_byte_infos	*byte;
	t_player		*player;
	int				offset;
	int				number;
	int				i;

	// TODO
	// probleme byte 0 ?
	i = 0;
	number = read_register(reg, 1);
	//swap_endianess((char *)&number, (char *)reg, REG_SIZE);
	offset = pc - g_corewar.cycle_infos.arena;
	while (i < REG_SIZE)
	{
		if (offset + i < MEM_SIZE)
			byte = &g_corewar.cycle_infos.byte_infos[offset + i];
		else
			byte = &g_corewar.cycle_infos.byte_infos[i];
		byte->op = 50;
		if ((player = find_player(number)))
			byte->number = player->id;
		i++;
	}
}

int		store_register(t_registry *reg, int idx, char *value_ptr)
{
	if (idx < 1 || idx >= REG_NUMBER)
		return (0);
	swap_endianess((char *)&reg[idx - 1], value_ptr, REG_SIZE);
	return (1);
}

int		store_addr_register(t_registry *reg, int idx, char *pc)
{
	char	*memory;
	int		overflow;

	if (idx < 1 || idx >= REG_NUMBER)
		return (0);
	memory = g_corewar.cycle_infos.arena;
	if (pc < memory)
		pc = (memory + MEM_SIZE) + ((pc - memory) % MEM_SIZE);
	overflow = (pc + REG_SIZE) - (memory + MEM_SIZE);
	if (overflow > 0)
	{
		if (overflow > REG_SIZE)
		{
			overflow -= REG_SIZE;
			ft_memcpy((void *)reg[idx - 1],
					(void *)(memory + overflow), REG_SIZE);
		}
		else
		{
			ft_memcpy((void *)reg[idx - 1], (void *)pc,
											REG_SIZE - overflow);
			ft_memcpy((void *)&reg[idx - 1][REG_SIZE - overflow],
					(void *)memory, overflow);
		}
	}
	else
		ft_memcpy((void *)reg[idx - 1], (void *)pc, REG_SIZE);
	return (1);
}

int		write_register(t_registry *reg, int idx, char *pc)
{
	char	*memory;
	int		overflow;

	if (idx < 1 || idx >= REG_NUMBER)
		return (0);
	memory = g_corewar.cycle_infos.arena;
	if (pc < memory)
		pc = (memory + MEM_SIZE) + ((pc - memory) % MEM_SIZE);
	overflow = (pc + REG_SIZE) - (memory + MEM_SIZE);
	if (overflow > 0)
	{
		if (overflow > REG_SIZE)
		{
			overflow -= REG_SIZE;
			ft_memcpy((void *)(memory + overflow),
					(void *)reg[idx - 1], REG_SIZE);
		}
		else
		{
			ft_memcpy((void *)pc, (void *)reg[idx - 1], REG_SIZE - overflow);
			ft_memcpy((void *)memory,
					(void *)&reg[idx - 1][REG_SIZE - overflow], overflow);
		}
	}
	else
		ft_memcpy((void *)pc, (void *)reg[idx - 1], REG_SIZE);
	mark_byte(pc, reg);
	return (1);
}

int		copy_register(t_registry *reg, int dst_idx, int src_idx)
{
	t_registry	*dst;
	t_registry	*src;
	int			i;

	if (dst_idx < 1 || dst_idx >= REG_NUMBER
			|| src_idx < 1 || src_idx >= REG_NUMBER)
		return (0);
	dst = &reg[dst_idx - 1];
	src = &reg[src_idx - 1];
	i = 0;
	while (i < REG_SIZE)
	{
		(*dst)[i] = (*src)[i];
		i++;
	}
	return (1);
}
