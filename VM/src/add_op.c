/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:37 by akopera           #+#    #+#             */
/*   Updated: 2017/02/10 20:31:28 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add_op(t_proc *proc, t_op_arg args[3])
{
	int		vals[3];

	ft_printf("add   ");
	swap_endianess((char *)&vals[0], (char *)&proc->reg[args[0].value], args[0].value);
	swap_endianess((char *)&vals[1], (char *)&proc->reg[args[1].value], args[1].value);
	vals[2] = vals[0] + vals[1];
	swap_endianess((char *)&proc->reg[args[2].value], (char *)&vals[2], args[2].value);
}
