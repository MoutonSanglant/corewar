/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:37 by akopera           #+#    #+#             */
/*   Updated: 2017/03/13 01:28:05 by tdefresn         ###   ########.fr       */
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
		return ;
	sum = a + b;
	store_register(proc->reg, args[2].value, (char *)&sum);
	if (g_corewar.reg_error)
		return ;
	if (sum != 0)
		proc->carry = 0;
	else
		proc->carry = 1;
}
