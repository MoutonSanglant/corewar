/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 20:45:16 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/15 02:31:59 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		get_type_of_arg(t_op_arg *arg, char ocp, int opcode)
{
	if (ocp == REG_CODE)
	{
		//ft_printf("REG, ocp: %x\n", ocp);
		arg->type = T_REG;
		arg->size = 1;
	}
	else if (ocp == IND_CODE)
	{
		arg->type = T_IND;
		arg->size = IND_SIZE;
	}
	else if (ocp == DIR_CODE)
	{
		arg->type = T_DIR;
		if (g_op_tab[opcode].dir_short)
			arg->size = IND_SIZE;
		else
			arg->size = DIR_SIZE;
	}
}

static size_t	check_args(t_op_arg args[3], char ocp, int opcode,
											int count)
{
	args[1].type = 0;
	args[1].size = 0;
	args[2].type = 0;
	args[2].size = 0;
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
	get_type_of_arg(&args[0], ocp >> 6 & 0b11, opcode);
	if (count > 1)
		get_type_of_arg(&args[1], ocp >> 4 & 0b11, opcode);
	if (count > 2)
		get_type_of_arg(&args[2], ocp >> 2 & 0b11, opcode);
	return (2);
}

static void		get_arguments(char *pc, t_op_arg args[3], int args_count)
{
	char	*value_ptr;
	int		offset;
	int		size;
	int		i;
	int		j;

	i = 0;
	offset = 0;
	while (i < args_count)
	{
		j = 0;
		size = args[i].size;
		value_ptr = (char *)&args[i].value;
		while (j < size)
		{
			value_ptr[size - (j + 1)] = read_byte(pc + offset + j);
			j++;
		}
		//swap_endianess((char *)&args[i].value, (char *)&pc[offset],
		//	args[i].size);
		offset += args[i].size;
		i++;
	}
}

size_t			get_argument_op(t_proc *proc, int opcode, t_op_arg args[3])
{
	size_t	offset;
	int		args_count;
	int		args_sizes;

	ft_bzero(args, sizeof(t_op_arg) * 3);
	args_count = 3;
	if (opcode == 0x10)
		args_count = 1;
	else if (opcode == 0x0d || opcode == 0x02 || opcode == 0x03)
		args_count = 2;
	offset = check_args(args, read_byte(proc->pc + 1), opcode - 1, args_count);
	args_sizes = args[0].size + args[1].size + args[2].size;
	if (args_sizes > 0)
		get_arguments((char *)&proc->pc[offset], args, args_count);
	return (offset + args_sizes);
}
