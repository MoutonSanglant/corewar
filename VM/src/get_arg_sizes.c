/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_sizes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:15:30 by akopera           #+#    #+#             */
/*   Updated: 2017/01/27 19:57:28 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	get_type_of_arg(char octet_codage, int opc)
{
	if (octet_codage == REG_CODE)
	{
		ft_printf(" REG");
		return (1); // REG
	}
	else if (octet_codage == IND_CODE)
	{
		ft_printf(" IND");
		return (IND_SIZE); // IND
	}
	else if (octet_codage == DIR_CODE)
	{
		ft_printf(" DIR");
		if (opc >= 9 && opc <= 15 && opc != 13) // TODO Passer par la struct op.c
			return (IND_SIZE); // DIR
		else
			return(DIR_SIZE);
	}
	ft_printf(" XXX");
	return (0); // PAS D'ARGUMENT
}

int	*get_argument_sizes(char octet_codage, int opcode, t_player *player)
{
	int *argument_sizes;

	ft_printf("OPCODE: %2d, OC : %x, ARGS : ", opcode, octet_codage & 0xff);
	argument_sizes = (int*)malloc(sizeof(int) * 3); //TODO FREE
	argument_sizes[0] = get_type_of_arg(octet_codage >> 6 & 0b11, opcode);
	argument_sizes[1] = get_type_of_arg(octet_codage >> 4 & 0b11, opcode);
	argument_sizes[2] = get_type_of_arg(octet_codage >> 2 & 0b11, opcode);

	player->next_op += argument_sizes[0] + argument_sizes[1] + argument_sizes[2] + 2;
	ft_printf(", NEXT OP : %d\n", (int)player->next_op[0]);
/*
**	DEBUG & TESTS
*/
/*
	char *arg1;
	char *arg2;
	char *arg3;

	if (argument_sizes[0] == 1)
		arg1 = ft_strdup("REG");
	else if (argument_sizes[0] == IND_SIZE)
		arg1 = ft_strdup("IND");
	else if (argument_sizes[0] == DIR_SIZE)
		arg1 = ft_strdup("DIR");
	else
		arg1 = ft_strdup("NO ARG");

	if (argument_sizes[1] == 1)
		arg2 = ft_strdup("REG");
	else if (argument_sizes[1] == IND_SIZE)
		arg2 = ft_strdup("IND");
	else if (argument_sizes[1] == DIR_SIZE)
		arg2 = ft_strdup("DIR");
	else
		arg2 = ft_strdup("NO ARG");

	if (argument_sizes[2] == 1)
		arg3 = ft_strdup("REG");
	else if (argument_sizes[2] == IND_SIZE)
		arg3 = ft_strdup("IND");
	else if (argument_sizes[2] == DIR_SIZE)
		arg3 = ft_strdup("DIR");
	else
		arg3 = ft_strdup("NO ARG");

	ft_printf("ARG 1 : %s, ARG 2 : %s, ARG 3: %s\n", arg1, arg2, arg3);
*/
/*
**	FIN DEBUG VERIFICATION
*/
	return (argument_sizes);
}
