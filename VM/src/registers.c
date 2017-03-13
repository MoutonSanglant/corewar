/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:14:49 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/12 23:16:18 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	mark_byte(char *pc, t_registry *reg)
{
	t_byte_infos	*byte;
	t_player		*player;
	int				offset;
	int				number;
	int				i;

	i = 0;
	number = read_register(reg, 1);
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

/*
** idx sera toujours une valeur comprise entre 1 et REG_NUMBER
*/

int			read_register(t_registry *reg, int idx)
{
	int	value;

	if (idx < 1 || idx > REG_NUMBER)
	{
		g_corewar.reg_error = 1;
		return (0);
	}
	swap_endianess((char *)&value, (char *)&reg[idx - 1], REG_SIZE);
	return (value);
}

int			store_register(t_registry *reg, int idx, char *value_ptr)
{
	if (idx < 1 || idx > REG_NUMBER)
	{
		g_corewar.reg_error = 1;
		return (0);
	}
	swap_endianess((char *)&reg[idx - 1], value_ptr, REG_SIZE);
	return (1);
}

int			store_addr_register(t_registry *reg, int idx, char *pc)
{
	char	*mem;
	int		overflow;

	if (idx < 1 || idx > REG_NUMBER)
	{
		g_corewar.reg_error = 1;
		return (0);
	}
	if ((mem = g_corewar.cycle_infos.arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	if (pc > mem + MEM_SIZE)
	{
		overflow = (pc - (mem + MEM_SIZE)) % MEM_SIZE;
		pc = mem + overflow;
	}
	if ((overflow = pc + REG_SIZE - (mem + MEM_SIZE)) > 0)
	{
		ft_memcpy((void *)reg[idx - 1], (void *)pc, REG_SIZE - overflow);
		ft_memcpy((void *)&reg[idx - 1][REG_SIZE - overflow], (void *)mem,
																	overflow);
	}
	else
		ft_memcpy((void *)reg[idx - 1], (void *)pc, REG_SIZE);
	return (1);
}

int			write_register(t_registry *reg, char *pc, int idx)
{
	char	*mem;
	int		overflow;

	if (idx < 1 || idx > REG_NUMBER)
	{
		g_corewar.reg_error = 1;
		return (0);
	}
	if ((mem = g_corewar.cycle_infos.arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	if (pc > mem + MEM_SIZE)
	{
		overflow = (pc - (mem + MEM_SIZE)) % MEM_SIZE;
		pc = mem + overflow;
	}
	if ((overflow = pc + REG_SIZE - (mem + MEM_SIZE)) > 0)
	{
		ft_memcpy((void *)pc, (void *)reg[idx - 1], REG_SIZE - overflow);
		ft_memcpy((void *)mem, (void *)&reg[idx - 1][REG_SIZE - overflow],
																overflow);
	}
	else
		ft_memcpy((void *)pc, (void *)reg[idx - 1], REG_SIZE);
	mark_byte(pc, reg);
	return (1);
}

int			copy_register(t_registry *reg, int dst_idx, int src_idx)
{
	if (dst_idx < 1 || dst_idx > REG_NUMBER
			|| src_idx < 1 || src_idx > REG_NUMBER)
	{
		g_corewar.reg_error = 1;
		return (0);
	}
	ft_memcpy((void *)&reg[dst_idx - 1], (void *)&reg[src_idx - 1], REG_SIZE);
	return (1);
}
