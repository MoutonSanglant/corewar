/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:37 by akopera           #+#    #+#             */
/*   Updated: 2017/02/17 20:38:14 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add_op(t_proc *proc, t_op_arg args[3])
{
	int		sum;
	int		a;
	int		b;

	proc->carry = 0;
	a = read_register(proc->reg, args[0].value);
	if (a < 0)
		return ;
	b = read_register(proc->reg, args[1].value);
	if (b < 0)
		return ;
	sum = a + b;
	store_register(proc->reg, args[2].value, (char *)&sum);
	proc->carry = 2;
}
