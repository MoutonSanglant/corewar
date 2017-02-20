/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:25:05 by akopera           #+#    #+#             */
/*   Updated: 2017/02/20 19:26:27 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp_op(t_proc *proc, t_op_arg args[3])
{
	if (proc->carry)
		process_move(proc, (short)args[0].value % IDX_MOD);
	else
		process_move(proc, 3);
}
