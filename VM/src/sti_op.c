/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:25:47 by akopera           #+#    #+#             */
/*   Updated: 2017/02/15 21:23:08 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti_op(t_proc *proc, t_op_arg args[3])
{
	int	i;
	int	conv;

	i = 0;
	conv = 0;
	//ft_printf("sti   ");
	if (args[1].type == T_DIR && (args[0].value - 1) >= 0)
		i += args[1].value;
	if (args[1].type == T_IND && (args[0].value - 1) >= 0)
	{
		swap_endianess((char*)&conv, proc->pc + args[1].value, IND_SIZE);
		i += conv;
	}
	if (args[1].type == T_REG && (args[0].value - 1) >= 0)
		i += read_register(proc->reg, args[0].value);
	if (args[2].type == T_DIR && (args[0].value - 1) >= 0)
		i += args[2].value;
	if (args[2].type == T_REG && (args[0].value - 1) >= 0)
		i += read_register(proc->reg, args[0].value);
	write_register(proc->reg, args[0].value, proc->pc + i);
}
