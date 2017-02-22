/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:22:50 by akopera           #+#    #+#             */
/*   Updated: 2017/02/22 12:42:36 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld_op(t_proc *proc, t_op_arg args[3])
{
	int	value;

	args[1].value = args[1].value % IDX_MOD;
	proc->carry = 0;
	value = get_value(proc, args, 0, 0);
	store_register(proc->reg, args[1].value, (char *)&value);
	proc->carry = !value;
}
