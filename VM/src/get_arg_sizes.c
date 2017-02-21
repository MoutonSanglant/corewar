/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_sizes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:15:30 by akopera           #+#    #+#             */
/*   Updated: 2017/02/21 17:49:13 by tdefresn         ###   ########.fr       */
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
											t_op_arg args[3], int args_count)
{
	int	i;

	if (!g_op_tab[opcode].ocp)
	{
		if (g_op_tab[opcode].dir_short)
			args[0].size = IND_SIZE;
		else
			args[0].size = DIR_SIZE;
		return (1);
	}
	i = 0;
	while (i < args_count)
	{
		get_type_of_arg(&args[i], octet_codage >> (6 - (2 * i)) & 0b11, opcode);
		i++;
	}
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

	args_count = 3;
	if (opcode == 0x0d || opcode == 0x02 || opcode == 0x03)
		args_count = 2;
	offset = get_argument_sizes(proc->pc[1], opcode - 1, args, args_count);
	get_arguments((char *)&proc->pc[offset], args, args_count);
	return (offset + args[0].size + args[1].size + args[2].size);
}
