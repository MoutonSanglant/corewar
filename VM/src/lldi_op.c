/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:27:22 by akopera           #+#    #+#             */
/*   Updated: 2017/02/10 20:13:36 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lldi_op(t_proc *proc, t_op_arg args[3])
{
	int	i;
	int	conv;

	
	conv = 0;
	i = 0;
	ft_printf("lldi   ");
	if (args[0].type == T_REG)
		i += read_register(proc->reg, args[0].value);
	if (args[0].type == T_DIR)
		i += args[0].value;
	if (args[0].type == T_IND)
	{
		swap_endianess((char*)&conv, proc->pc + args[0].value, IND_SIZE);
		i += conv;
	}
	if (args[1].type == T_REG)
		i += read_register(proc->reg, args[1].value);
	if (args[1].type == T_DIR)
		i += args[1].value;
	ft_memcpy(proc->reg[args[2].value - 1], proc->pc + i, REG_SIZE);
	proc->carry = 1;
}
