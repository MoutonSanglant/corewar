/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:52 by akopera           #+#    #+#             */
/*   Updated: 2017/02/10 20:10:47 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sub_op(t_proc *proc, t_op_arg args[3])
{
	int		a[3];
	int		vals[3];
	int		offset;
	int		i;

	ft_printf("sub   ");
	//get_argument_sizes(*(proc->pc + 1), (int)proc->pc[0], arg_s);
	i = 0;
	offset = 2;
	while (i < 3)
	{
		swap_endianess((char *)&a[i], (char *)&proc->pc[offset], args[i].size);
		offset += args[i].size;
		i++;
	}
	swap_endianess((char *)&vals[0], (char *)&proc->reg[a[0]], a[0]);
	swap_endianess((char *)&vals[1], (char *)&proc->reg[a[1]], a[1]);
	vals[2] = vals[0] - vals[1];
	swap_endianess((char *)&proc->reg[a[2]], (char *)&vals[2], a[2]);
}
