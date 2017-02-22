/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:18 by akopera           #+#    #+#             */
/*   Updated: 2017/02/22 21:11:50 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st_op(t_proc *proc, t_op_arg args[3])
{
	int		offset;
	//int		val;
	int		r1;

	r1 = args[0].value;
	//val = get_value(proc, args, 1, 0);
		//offset = get_value(proc, args, 1, 0);
	if (g_corewar.reg_error)
		return ;
	if (args[1].type == T_IND)
	{
		//store_register(proc->reg, idx, (char *)&val);
		offset = args[1].value;
		write_register(proc->reg, proc->pc + offset, r1);
	}
	else if (args[1].type == T_REG)
		//copy_register(proc->reg, get_value(proc, args, 1, 0), idx);
		copy_register(proc->reg, args[1].value, r1);
}
