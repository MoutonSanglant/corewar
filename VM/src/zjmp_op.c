/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:25:05 by akopera           #+#    #+#             */
/*   Updated: 2017/02/17 20:09:41 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp_op(t_proc *proc, t_op_arg args[3])
{
	if (proc->carry)
		process_move(proc, args[0].value % IDX_MOD);
}
