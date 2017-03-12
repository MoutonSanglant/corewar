/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:25:47 by akopera           #+#    #+#             */
/*   Updated: 2017/03/12 17:31:20 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti_op(t_proc *proc, t_op_arg args[3])
{
	int		idx;
	int		a;
	int		b;

	a = get_value(proc, args, 1, 0);
	b = get_value(proc, args, 2, 0);
	//if (g_corewar.reg_error)
	//	return ;
	idx = (a + b) % IDX_MOD;
	write_register(proc->reg, proc->pc + idx, args[0].value);
}
