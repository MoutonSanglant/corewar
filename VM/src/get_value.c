/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:38:23 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/21 22:10:43 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	read_memory(char *dst, char *pc)
{
	char	*memory;
	int		overflow;

	memory = g_corewar.cycle_infos.arena;
	if (pc < memory)
		pc = (memory + MEM_SIZE) + ((pc - memory) % MEM_SIZE);
	overflow = (pc + REG_SIZE) - (memory + MEM_SIZE);
	if (overflow > 0)
	{
		if (overflow > REG_SIZE)
		{
			overflow %= MEM_SIZE;
			overflow -= REG_SIZE;
			ft_memcpy((void *)dst, (void *)(memory + overflow), REG_SIZE);
		}
		else
		{
			ft_memcpy((void *)dst, (void *)pc, REG_SIZE - overflow);
			ft_memcpy((void *)&dst[REG_SIZE - overflow],
											(void *)memory, overflow);
		}
	}
	else
		ft_memcpy((void *)dst, (void *)pc, REG_SIZE);
}

int			get_value(t_op_arg *arg, t_arg_type mask, t_proc *p, int size_mod)
{
	int		value;
	int		mem_chunk;

	mem_chunk = 0;
	value = 0;
	if (!(arg->type & mask))
		return (0);
	if (arg->type & T_DIR)
		value = (size_mod) ? (short)arg->value : arg->value;
	else if (arg->type & T_IND)
	{
		read_memory((char *)&mem_chunk, p->pc + arg->value);
		swap_endianess((char*)&value, (char *)&mem_chunk, REG_SIZE);
		value = (short)value;
	}
	else if (arg->type & T_REG)
		value = (size_mod) ? (short)read_register(p->reg, arg->value)
							: read_register(p->reg, arg->value);
	return (value);
}
