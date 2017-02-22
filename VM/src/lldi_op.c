/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:27:22 by akopera           #+#    #+#             */
/*   Updated: 2017/02/22 12:57:44 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lldi_op(t_proc *proc, t_op_arg args[3])
{
	int	a;
	int	b;
	int	idx;

	a = get_value(proc, args, 0, 1);
	b = get_value(proc, args, 1, 1);
	if (g_corewar.reg_error)
		return ;
	idx = a + b;
	store_addr_register(proc->reg, (char)args[2].value, proc->pc + idx);
	proc->carry = read_register(proc->reg, (char)args[2].value);
}
