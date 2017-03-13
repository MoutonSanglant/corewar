/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:24:06 by akopera           #+#    #+#             */
/*   Updated: 2017/03/13 01:28:14 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	and_op(t_proc *proc, t_op_arg args[3])
{
	int		r;
	int		a;
	int		b;

	a = get_value(proc, args, 0, 0);
	b = get_value(proc, args, 1, 0);
	if (g_corewar.reg_error)
		return ;
	r = a & b;
	store_register(proc->reg, args[2].value, (char *)&r);
	if (g_corewar.reg_error)
		return ;
	if (r != 0)
		proc->carry = 0;
	else
		proc->carry = 1;
}
