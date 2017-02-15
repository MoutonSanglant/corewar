/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:24:06 by akopera           #+#    #+#             */
/*   Updated: 2017/02/15 21:22:40 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	and_op(t_proc *proc, t_op_arg args[3])
{
	int	a;
	int	b;
	int	r;

	//ft_printf("and   \n");
	a = get_value(&args[0], T_REG | T_DIR | T_IND, proc);
	b = get_value(&args[1], T_REG | T_DIR | T_IND, proc);
	r = a & b;
	if (store_register(proc->reg, args[2].value, (char *)&r))
		proc->carry = r;
}
