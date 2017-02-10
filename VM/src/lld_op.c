/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:27:01 by akopera           #+#    #+#             */
/*   Updated: 2017/02/10 20:35:32 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lld_op(t_proc *proc, t_op_arg args[3])
{
	t_registry	*reg;

	ft_printf("ld    ");
	if (args[1].value < REG_NUMBER)
	{
		reg = &proc->reg[args[1].value];
		swap_endianess((char *)reg, (char *)&args[0].value, sizeof(t_registry));
		proc->carry = 1;
	}
}
