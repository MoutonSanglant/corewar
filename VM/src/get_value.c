/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:38:23 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/22 13:34:08 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	read_memory(char *dst, char *pc)
{
	char	*mem;
	int		overflow;

	if ((mem = g_corewar.cycle_infos.arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	if (pc > mem + MEM_SIZE)
	{
		overflow = (pc - (mem + MEM_SIZE)) % MEM_SIZE;
		pc = mem + overflow;
	}
	if ((overflow = pc + REG_SIZE - (mem + MEM_SIZE)) > 0)
	{
		ft_memcpy((void *)dst, (void *)pc, REG_SIZE - overflow);
		ft_memcpy((void *)&dst[REG_SIZE - overflow], (void *)mem, overflow);
	}
	else
		ft_memcpy((void *)dst, (void *)pc, REG_SIZE);
}

int			get_value(t_proc *p, t_op_arg *arg, int	idx, int long_op)
{
	t_arg_type	mask;
	int			size_mod;
	int			mem_chunk;
	int			value;

	arg = &arg[idx];
	size_mod = p->op->dir_short;
	mask = p->op->arg_type[idx];
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
		if (!long_op)
			value %= IDX_MOD;
	}
	else if (arg->type & T_REG)
		value = read_register(p->reg, arg->value);
	return (value);
}
