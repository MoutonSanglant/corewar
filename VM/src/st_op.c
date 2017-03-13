/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:18 by akopera           #+#    #+#             */
/*   Updated: 2017/03/12 23:06:48 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st_op(t_proc *proc, t_op_arg args[3])
{
	int		offset;
	int		r1;

	r1 = args[0].value;
	if (args[1].type == T_IND)
	{
		offset = ((short)args[1].value) % IDX_MOD;
		write_register(proc->reg, proc->pc + offset, r1);
	}
	else if (args[1].type == T_REG)
		copy_register(proc->reg, args[1].value, r1);
}
