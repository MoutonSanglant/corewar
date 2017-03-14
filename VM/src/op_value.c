/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_value.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 20:50:30 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/14 21:33:20 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_value(t_proc *p, t_op_arg *arg, int	idx, int long_op)
{
	t_arg_type	mask;
	int			size_mod;
	int			value;
	int			tmp;

	arg = &arg[idx];
	size_mod = p->op->dir_short;
	mask = p->op->arg_type[idx];
	value = 0;
	if (!(arg->type & mask))
		return (0);
	if (arg->type & T_DIR)
		value = (size_mod) ? (short)arg->value : arg->value;
	else if (arg->type & T_IND)
	{
		arg->value = ((short)arg->value);
		if (!long_op)
			arg->value %= IDX_MOD;
		tmp = 0;
		read_range((char *)&tmp, p->pc + arg->value, DIR_SIZE);
		//read_memory((char *)&tmp, p->pc + arg->value);
		swap_endianess((char*)&value, (char *)&tmp, DIR_SIZE);
	}
	else if (arg->type & T_REG)
		value = read_register(p->reg, arg->value);
	return (value);
}
