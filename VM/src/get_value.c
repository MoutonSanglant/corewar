/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:38:23 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/15 20:00:11 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_value(t_op_arg *arg, t_arg_type mask, t_proc *proc)
{
	int		value;

	value = 0;
	if (!(arg->type & mask))
		return (0);
	if (arg->type & T_DIR)
		value = arg->value;
	else if (arg->type & T_IND)
	{
		// TODO: vérifier la taille à utiliser
		swap_endianess((char*)&value, proc->pc + arg->value, IND_SIZE);
	}
	else if (arg->type & T_REG)
		value = read_register(proc->reg, arg->value);
	return (value);
}
