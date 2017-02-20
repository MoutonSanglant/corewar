/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_sizes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:15:30 by akopera           #+#    #+#             */
/*   Updated: 2017/02/20 17:59:18 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		get_type_of_arg(t_op_arg *arg, char octet_codage, int opc)
{
	if (octet_codage == REG_CODE)
	{
		arg->type = T_REG;
		arg->size = 1;
	}
	else if (octet_codage == IND_CODE)
	{
		arg->type = T_IND;
		arg->size = IND_SIZE;
	}
	else if (octet_codage == DIR_CODE)
	{
		arg->type = T_DIR;
		if (g_op_tab[opc].dir_short)
			arg->size = IND_SIZE;
		else
			arg->size = DIR_SIZE;
	}
}

static size_t	get_argument_sizes(char octet_codage, int opcode,
	t_op_arg args[3])
{
	if (!g_op_tab[opcode].ocp)
	{
		if (g_op_tab[opcode].dir_short)
			args[0].size = IND_SIZE;
		else
			args[0].size = DIR_SIZE;
		return (1);
	}
	get_type_of_arg(&args[0], octet_codage >> 6 & 0b11, opcode);
	get_type_of_arg(&args[1], octet_codage >> 4 & 0b11, opcode);
	get_type_of_arg(&args[2], octet_codage >> 2 & 0b11, opcode);
	return (2);
}

static void		get_arguments(char *pc, t_op_arg args[3])
{
	int		offset;
	int		i;

	i = 0;
	offset = 0;
	while (i < 3)
	{
		swap_endianess((char *)&args[i].value, (char *)&pc[offset],
			args[i].size);
		offset += args[i].size;
		i++;
	}
}

size_t			get_argument_op(t_proc *proc, int opcode, t_op_arg args[3])
{
	size_t	offset;

	offset = get_argument_sizes(proc->pc[1], opcode - 1, args);
	get_arguments((char *)&proc->pc[offset], args);
	return (offset + args[0].size + args[1].size + args[2].size);
}
