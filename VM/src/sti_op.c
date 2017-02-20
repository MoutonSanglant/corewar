/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:25:47 by akopera           #+#    #+#             */
/*   Updated: 2017/02/20 23:34:41 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti_op(t_proc *proc, t_op_arg args[3])
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = get_value(&args[1], T_DIR | T_IND | T_REG, proc, 1);
	b = get_value(&args[2], T_DIR | T_REG, proc, 1);
	i = a + b;
	i %= IDX_MOD;
	write_register(proc->reg, args[0].value, proc->pc + i);
}
