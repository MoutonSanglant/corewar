/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:28:13 by akopera           #+#    #+#             */
/*   Updated: 2017/03/12 17:22:38 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_reg(t_proc *proc, t_op_arg args[3])
{
	int		val;

	val = read_register(proc->reg, args[0].value);
	if (!g_corewar.reg_error)
		ft_printf("%c", val);
}

void		aff_op(t_proc *proc, t_op_arg args[3])
{
	if (g_corewar.flags & FLAG_NCUR)
	{
		g_corewar.cycle_infos.aff[0] = proc->id;
		g_corewar.cycle_infos.aff[1] = args[0].value;
		g_corewar.cycle_infos.aff[2] = read_register(proc->reg, args[0].value);
		g_corewar.cycle_infos.aff[3] = proc->carry;
	}
	else
		print_reg(proc, args);
}
