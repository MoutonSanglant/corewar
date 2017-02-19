/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:27:01 by akopera           #+#    #+#             */
/*   Updated: 2017/02/17 20:18:01 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lld_op(t_proc *proc, t_op_arg args[3])
{
	proc->carry = 0;
	if (args[1].value < REG_NUMBER)
	{
		if (args[0].type == T_DIR)
			store_register(proc->reg, args[1].value, (char *)&args[0].value);
		if (args[0].type == T_IND)
			store_register(proc->reg, args[1].value,
				proc->pc + (args[0].value % IDX_MOD));
		proc->carry = 1;
	}
}
