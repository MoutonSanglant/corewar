/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:27:22 by akopera           #+#    #+#             */
/*   Updated: 2017/02/20 23:35:37 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lldi_op(t_proc *proc, t_op_arg args[3])
{
	int	a;
	int	b;
	int	i;

	proc->carry = 0;
	a = get_value(&args[0], T_DIR | T_REG | T_IND, proc, 1);
	b = get_value(&args[1], T_DIR | T_REG, proc, 1);
	i = a + b;
	store_addr_register(proc->reg, (short)args[2].value, proc->pc + i);
	proc->carry = read_register(proc->reg, (short)args[2].value);
}
