/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:27:01 by akopera           #+#    #+#             */
/*   Updated: 2017/02/07 14:28:47 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lld_op(t_proc *proc)
{
	t_registry	*reg;
	int			arg_s[2];
	int			args[2];
	int			offset;
	int			i;

	ft_printf("ld    ");
	get_argument_sizes(*(proc->pc + 1), (int)proc->pc[0], arg_s);
	i = 0;
	offset = 2;
	while (i < 2)
	{
		swap_endianess((char *)&args[i], (char *)&proc->pc[offset], arg_s[i]);
		offset += arg_s[i];
		i++;
	}
	if (args[1] < REG_NUMBER)
	{
		reg = &proc->reg[args[1]];
		swap_endianess((char *)reg, (char *)&args[0], sizeof(t_registry));
		proc->carry = 1;
	}
}
