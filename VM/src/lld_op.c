/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:27:01 by akopera           #+#    #+#             */
/*   Updated: 2017/02/10 20:35:32 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lld_op(t_proc *proc, t_op_arg args[3])
{
	ft_printf("lld    ", args[1].value);
	if (args[1].value < 1)
		return ;
	// récupération du registre r(arg2)
	if (args[1].value < REG_NUMBER)
	{
		// stocke arg1 dans reg
		if (args[0].type == T_DIR)
			store_register(proc->reg, args[1].value, (char *)&args[0].value);
			//swap_endianess((char *)reg, (char *)&args[0].value, sizeof(t_registry));
		if (args[0].type == T_IND)
			store_register(proc->reg, args[1].value, proc->pc + (args[0].value % IDX_MOD));
			//swap_endianess((char *)reg, proc->pc + (args[0].value % IDX_MOD), sizeof(t_registry));
		proc->carry = 1;
	}
}
