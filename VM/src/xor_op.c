/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:24:46 by akopera           #+#    #+#             */
/*   Updated: 2017/02/07 14:28:47 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	xor_op(t_proc *proc)
{
	int	arg_sizes[3];

	ft_printf("xor   ");
	get_argument_sizes(*(proc->pc + 1), (int)proc->pc[0], arg_sizes);
	
}
