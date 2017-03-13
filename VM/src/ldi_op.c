/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:25:31 by akopera           #+#    #+#             */
/*   Updated: 2017/03/13 23:20:59 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ldi_op(t_proc *proc, t_op_arg args[3])
{
	int		idx;
	int		a;
	int		b;
	int		r;

	a = get_value(proc, args, 0, 0);
	b = get_value(proc, args, 1, 0);
	if (g_corewar.reg_error)
		return ;
	idx = (a + b) % IDX_MOD;
	store_addr_register(proc->reg, (char)args[2].value, proc->pc + idx);
	r = read_register(proc->reg, (char)args[2].value);
}
