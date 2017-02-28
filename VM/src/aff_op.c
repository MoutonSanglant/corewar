/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:28:13 by akopera           #+#    #+#             */
/*   Updated: 2017/02/28 18:30:53 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_reg(t_proc *proc, t_op_arg args[3])
{
	char	*p_val;
	int		val;

	val = read_register(proc->reg, args[0].value);
	p_val = (char *)&val;
	ft_printf("r%i: %.2x %.2x %.2x %.2x\n", args[0].value,
											p_val[3] & 0xff,
											p_val[2] & 0xff,
											p_val[1] & 0xff,
											p_val[0] & 0xff);
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
