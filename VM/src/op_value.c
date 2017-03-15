/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_value.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 20:50:30 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/15 14:49:08 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_value(t_proc *proc, t_op_arg *arg, int idx, int long_op)
{
	char		buf[DIR_SIZE];
	t_arg_type	type;
	int			value;
	int			ret;

	ret = 0;
	type = arg[idx].type;
	value = arg[idx].value;

	//if (!(type & g_op_tab[opcode].arg_type[idx]))
	//if (!(type & proc->end_op->args_types[idx]))
	if (!(type & proc->start_op->args_types[idx]))
		return (0);
	else if (type & T_DIR)
		//ret = (g_op_tab[opcode].dir_short) ? (short)value : value;
		//ret = (proc->end_op->dir_short) ? (short)value : value;
		ret = (proc->start_op->dir_short) ? (short)value : value;
	else if (type & T_REG)
		read_register(get_register(proc->reg, value), (char *)&ret);
	else if (type & T_IND)
	{
		value = (long_op) ? (short)value : ((short)value) % IDX_MOD;
		ft_bzero(&buf, DIR_SIZE);
		read_range((char *)&buf, proc->pc + value, DIR_SIZE);
		swap_endianess((char*)&ret, (char *)&buf, DIR_SIZE);
	}
	return (ret);
}
