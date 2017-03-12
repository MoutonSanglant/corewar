/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:27:01 by akopera           #+#    #+#             */
/*   Updated: 2017/03/12 15:54:08 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lld_op(t_proc *proc, t_op_arg args[3])
{
	int		value;

	value = get_value(proc, args, 0, 1);
	store_register(proc->reg, args[1].value, (char *)&value);
	if (g_corewar.reg_error || value != 0)
//	if (value == 0)
		proc->carry = 0;
	else
		proc->carry = 1;
}
