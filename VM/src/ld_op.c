/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:22:50 by akopera           #+#    #+#             */
/*   Updated: 2017/02/07 14:28:47 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld_op(t_proc *proc)
{
	int	arg_sizes[3];
	int	arg_values[3];
	int*	test;


	ft_printf("ld    ");
	get_argument_sizes(*(proc->pc + 1), (int)proc->pc[0], arg_sizes);
	swap_endianess((char*)&arg_values[0], proc->pc + 2, arg_sizes[0]);
	ft_printf("\nValue arg 1 : %d, size arg 1 : %d \n", arg_values[0], arg_sizes[0]);
	if (arg_sizes[1])
	{
		swap_endianess((char*)&arg_values[1], proc->pc + 2 + arg_sizes[0], arg_sizes[1]);
		ft_printf("\nValue arg 2 : %d, size arg 2 : %d \n", arg_values[1], arg_sizes[1]);
	}
	if (arg_sizes[2])
	{
		swap_endianess((char*)&arg_values[2], proc->pc + 2 + arg_sizes[0] + arg_sizes[1], arg_sizes[2]);
		ft_printf("\nValue arg 3 : %d, size arg 3 : %d \n", arg_values[2], arg_sizes[2]);
	}
	test = (int*)proc->reg[arg_values[0] - 1];
	ft_printf("reg[%d] value : %d\n", arg_values[1], *test);
	//(int*)proc->reg[arg_values[0] - 1] = arg_values[0];
	ft_printf("reg[%d] value : %d\n", arg_values[1], *test);
}
