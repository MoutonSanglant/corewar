/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:24:46 by akopera           #+#    #+#             */
/*   Updated: 2017/02/22 13:11:01 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	xor_op(t_proc *proc, t_op_arg args[3])
{
	int	a;
	int	b;
	int	r;

	a = get_value(proc, args, 0, 0);
	b = get_value(proc, args, 1, 0);
	if (g_corewar.reg_error)
		return ;
	r = a ^ b;
	store_register(proc->reg, args[2].value, (char *)&r);
	proc->carry = !r;
}
