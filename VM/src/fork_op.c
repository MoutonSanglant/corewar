/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:26:17 by akopera           #+#    #+#             */
/*   Updated: 2017/02/13 23:13:58 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	fork_op(t_proc *proc, t_op_arg args[3])
{
	ft_printf("fork\n");
	process_fork(proc, args[0].value % IDX_MOD);
}
