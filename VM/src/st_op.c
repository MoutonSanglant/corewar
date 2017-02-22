/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:18 by akopera           #+#    #+#             */
/*   Updated: 2017/02/22 13:31:33 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st_op(t_proc *proc, t_op_arg args[3])
{
	int	idx;
	int	offset;

	idx = args[0].value;
	if (g_corewar.reg_error)
		return ;
	if (args[1].type == T_IND)
	{
		offset = (short)args[1].value % IDX_MOD;
		write_register(proc->reg, idx, proc->pc + offset);
	}
	if (args[1].type == T_REG)
	{
		copy_register(proc->reg, get_value(proc, args, 1, 0), idx);
	}
}
