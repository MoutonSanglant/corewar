/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:37 by akopera           #+#    #+#             */
/*   Updated: 2017/03/12 17:01:58 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add_op(t_proc *proc, t_op_arg args[3])
{
	int		sum;
	int		a;
	int		b;

	a = read_register(proc->reg, args[0].value);
	b = read_register(proc->reg, args[1].value);
	if (g_corewar.reg_error)
	{
		proc->carry = 0;
		return ;
	}
	sum = a + b;
	store_register(proc->reg, args[2].value, (char *)&sum);
	//if (g_corewar.reg_error)
	//	proc->carry = 0;
	//else if (sum == 0)
	if (g_corewar.reg_error || sum != 0)
//	if (sum == 0)
		proc->carry = 0;
	else
		proc->carry = 1;
}
