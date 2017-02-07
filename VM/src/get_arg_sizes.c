/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_sizes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:15:30 by akopera           #+#    #+#             */
/*   Updated: 2017/02/07 14:16:20 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	get_type_of_arg(char octet_codage, int opc)
{
	if (octet_codage == REG_CODE)
	{
		ft_printf(" REG");
		return (1);
	}
	else if (octet_codage == IND_CODE)
	{
		ft_printf(" IND");
		return (IND_SIZE);
	}
	else if (octet_codage == DIR_CODE)
	{
		ft_printf(" DIR");
		if (opc >= 9 && opc <= 15 && opc != 13)
			return (IND_SIZE);
		else
			return (DIR_SIZE);
	}
	ft_printf(" ___");
	return (0);
}

void	get_argument_sizes(char octet_codage, int opcode, int *arg_sizes)
{
	ft_printf("OPCODE: %2d, OC : %x, ARGS :", opcode, octet_codage & 0xff);
	arg_sizes[0] = get_type_of_arg(octet_codage >> 6 & 0b11, opcode);
	arg_sizes[1] = get_type_of_arg(octet_codage >> 4 & 0b11, opcode);
	arg_sizes[2] = get_type_of_arg(octet_codage >> 2 & 0b11, opcode);
	ft_printf("\n");
	//player->next_op += arg_sizes[0] + arg_sizes[1] + arg_sizes[2] + 2;
	//ft_printf(", NEXT OP : %d\n", (int)player->next_op[0]);
}
