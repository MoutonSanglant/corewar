/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:25:31 by akopera           #+#    #+#             */
/*   Updated: 2017/02/21 19:03:58 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ldi_op(t_proc *proc, t_op_arg args[3])
{
	int	i;
	int	a;
	int	b;

	a = get_value(&args[0], T_DIR | T_REG | T_IND, proc, 1);
	b = get_value(&args[1], T_DIR | T_REG, proc, 1);
	i = a + b;
	i %= IDX_MOD;
	store_addr_register(proc->reg, (short)args[2].value, proc->pc + i);
	proc->carry = read_register(proc->reg, (short)args[2].value);
}
