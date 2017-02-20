/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:24:06 by akopera           #+#    #+#             */
/*   Updated: 2017/02/20 21:01:30 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	and_op(t_proc *proc, t_op_arg args[3])
{
	int	a;
	int	b;
	int	r;

	proc->carry = 0;
	a = get_value(&args[0], T_REG | T_DIR | T_IND, proc, 0);
	b = get_value(&args[1], T_REG | T_DIR | T_IND, proc, 0);
	r = a & b;
	store_register(proc->reg, args[2].value, (char *)&r);
	proc->carry = !r;
}
