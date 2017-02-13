/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:27:40 by akopera           #+#    #+#             */
/*   Updated: 2017/02/13 20:48:17 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lfork_op(t_proc *proc, t_op_arg args[3])
{
	ft_printf("lfork \n");
	process_fork(proc, mem_goto(proc->pc + args[0].value));
}
