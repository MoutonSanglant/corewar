/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:37 by akopera           #+#    #+#             */
/*   Updated: 2017/02/08 20:08:08 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add_op(t_proc *proc)
{
	int		arg_s[3];
	int		args[3];
	int		vals[3];
	int		offset;
	int		i;

	ft_printf("add   ");
	get_argument_sizes(*(proc->pc + 1), (int)proc->pc[0], arg_s);
	i = 0;
	offset = 2;
	while (i < 3)
	{
		swap_endianess((char *)&args[i], (char *)&proc->pc[offset], arg_s[i]);
		offset += arg_s[i];
		i++;
	}
	swap_endianess((char *)&vals[0], (char *)&proc->reg[args[0]], args[0]);
	swap_endianess((char *)&vals[1], (char *)&proc->reg[args[1]], args[1]);
	vals[2] = vals[0] + vals[1];
	swap_endianess((char *)&proc->reg[args[2]], (char *)&vals[2], args[2]);
	ft_printf("copied value: %i\n", vals[2]);
}
