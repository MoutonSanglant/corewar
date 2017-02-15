/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:52 by akopera           #+#    #+#             */
/*   Updated: 2017/02/15 21:23:15 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sub_op(t_proc *proc, t_op_arg args[3])
{
	int		sum;
	int		a;
	int		b;

	//ft_printf("sub   ");
	a = read_register(proc->reg, args[0].value);
	if (a < 0)
		return ;
	b = read_register(proc->reg, args[1].value);
	if (b < 0)
		return ;
	sum = a - b;
	store_register(proc->reg, args[2].value, (char *)&sum);
}
