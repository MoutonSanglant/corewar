/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:18 by akopera           #+#    #+#             */
/*   Updated: 2017/02/21 19:05:07 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st_op(t_proc *proc, t_op_arg args[3])
{
	if (args[1].type == T_IND)
		write_register(proc->reg, args[0].value,
			proc->pc + (short)args[1].value % IDX_MOD);
	if (args[1].type == T_REG)
		copy_register(proc->reg, args[1].value, args[0].value);
}
