/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_sizes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:15:30 by akopera           #+#    #+#             */
/*   Updated: 2017/03/12 15:44:19 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		get_type_of_arg(t_op_arg *arg, char octet_codage, int ocp)
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
		if (g_op_tab[ocp].dir_short)
			arg->size = IND_SIZE;
		else
			arg->size = DIR_SIZE;
	}
}

static size_t	get_argument_sizes(char octet_codage, int opcode,
											t_op_arg args[3], int args_count)
{
	if (!g_op_tab[opcode].ocp)
	{
		if (g_op_tab[opcode].dir_short)
		{
			args[0].size = IND_SIZE;
			args[0].type = T_IND;
		}
		else
		{
			args[0].size = DIR_SIZE;
			args[0].type = T_DIR;
		}
		return (1);
	}
	get_type_of_arg(&args[0], octet_codage >> 6 & 0b11, opcode);
	args[1].type = 0;
	args[1].size = 0;
	args[2].type = 0;
	args[2].size = 0;
	if (args_count > 1)
		get_type_of_arg(&args[1], octet_codage >> 4 & 0b11, opcode);
	if (args_count > 2)
		get_type_of_arg(&args[2], octet_codage >> 2 & 0b11, opcode);
	return (2);
}

static void		get_arguments(char *pc, t_op_arg args[3], int args_count)
{
	int		i;
	int		offset;

	i = 0;
	offset = 0;
	while (i < args_count)
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
	int		args_count;
	int		args_sizes;

	args_count = 3;
	if (opcode == 0x0d || opcode == 0x02 || opcode == 0x03)
		args_count = 2;
	if (opcode == 0x10)
		args_count = 1;
	offset = get_argument_sizes(proc->pc[1], opcode - 1, args, args_count);
	args_sizes = args[0].size + args[1].size + args[2].size;
	if (args_sizes > 0)
		get_arguments((char *)&proc->pc[offset], args, args_count);
	return (offset + args_sizes);
}
