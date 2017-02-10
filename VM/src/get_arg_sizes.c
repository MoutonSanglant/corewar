/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_sizes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:15:30 by akopera           #+#    #+#             */
/*   Updated: 2017/02/10 20:31:47 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_type_of_arg(t_op_arg *arg, char octet_codage, int opc)
{
	if (octet_codage == REG_CODE)
	{
		ft_printf(" REG");
		arg->type = T_REG;
		arg->size = 1;
		//return (1);
	}
	else if (octet_codage == IND_CODE)
	{
		ft_printf(" IND");
		arg->type = T_IND;
		arg->size = IND_SIZE;
		//return (IND_SIZE);
	}
	else if (octet_codage == DIR_CODE)
	{
		ft_printf(" DIR");
		arg->type = T_DIR;
		if (opc >= 9 && opc <= 15 && opc != 13)
			arg->size = IND_SIZE;
			//return (IND_SIZE);
		else
			arg->size = DIR_SIZE;
			//return (DIR_SIZE);
	}
	else
	{
		ft_printf(" ___");
	}
	//return (0);
}

void	get_argument_sizes(char octet_codage, int opcode, t_op_arg args[3])
{

	ft_printf("OPCODE: %2d, OC : %x, ARGS : ", opcode, octet_codage & 0xff);
	get_type_of_arg(&args[0], octet_codage >> 6 & 0b11, opcode);
	get_type_of_arg(&args[1], octet_codage >> 4 & 0b11, opcode);
	get_type_of_arg(&args[2], octet_codage >> 2 & 0b11, opcode);
//	arg_values = read_arg(player, arg_sizes);
//	player->next_op += arg_sizes[0] + arg_sizes[1] + arg_sizes[2] + 2;
//	ft_printf(", NEXT OP : %d\n", (int)player->next_op[0]);
//	return (arg_sizes);
}

static void	get_arguments(char *pc, t_op_arg args[3])
{
	int		offset;
	int		i;

	i = 0;
	offset = 0;
	while (i < 3)
	{
		swap_endianess((char *)&args[i].value, (char *)&pc[i], args[i].size);
		offset += args[i].size;
		i++;
	}
}

void	get_argument_op(t_proc *proc, int opcode, t_op_arg args[3])
{
	get_argument_sizes(proc->pc[1], opcode, args);
	get_arguments((char *)&proc->pc[2], args);
}
