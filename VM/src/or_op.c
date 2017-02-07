/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:24:31 by akopera           #+#    #+#             */
/*   Updated: 2017/02/07 14:28:47 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	or_op(t_proc *proc)
{
	int	arg_sizes[3];

	ft_printf("or    ");
	get_argument_sizes(*(proc->pc + 1), (int)proc->pc[0], arg_sizes);
	
}
