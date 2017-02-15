/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:18 by akopera           #+#    #+#             */
/*   Updated: 2017/02/14 12:55:19 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st_op(t_proc *proc, t_op_arg args[3])
{
	//char	*test;

	//test = proc->pc;
	//test += (args[1].value % IDX_MOD);
	ft_printf("st    \n");
	if (args[1].type == T_IND && (args[0].value - 1) >= 0)
	{
		write_register(proc->reg, args[0].value, proc->pc + args[1].value % IDX_MOD);
		//ft_memcpy((void*)test, (void*)proc->reg[args[0].value - 1], REG_SIZE);
	}
	if (args[1].type == T_REG && (args[0].value - 1) >= 0 && (args[1].value - 1) >= 0)
	{
		copy_register(proc->reg, args[1].value, args[0].value);
		//ft_memcpy((void*)&proc->reg[args[1].value - 1], (void*)&proc->reg[args[0].value - 1], REG_SIZE);
	}
}
