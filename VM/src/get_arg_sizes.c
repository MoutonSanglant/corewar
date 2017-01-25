/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_sizes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:15:30 by akopera           #+#    #+#             */
/*   Updated: 2017/01/25 19:00:35 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	get_type_of_arg(char octet_codage)
{
	if (octet_codage == 0b01)
		return (1); // REG
	else if (octet_codage == 0b11)
		return (2); // IND
	else if (octet_codage == 0b10)
		return (4); // DIR
	return (0); // PAS D'ARGUMENT
}

int	*get_argument_sizes(char octet_codage)
{
	int *argument_sizes;

	argument_sizes = (int*)malloc(sizeof(int) * 3);
	argument_sizes[0] = get_type_of_arg(octet_codage >> 6 & 0b11);
	argument_sizes[1] = get_type_of_arg(octet_codage >> 4 & 0b11);
	argument_sizes[2] = get_type_of_arg(octet_codage >> 2 & 0b11);


/*
**	DEBUG VERIFICATION
*/
	char *arg1;
	char *arg2;
	char *arg3;

	if (argument_sizes[0] == 1)
		arg1 = ft_strdup("REG");
	else if (argument_sizes[0] == 2)
		arg1 = ft_strdup("IND");
	else if (argument_sizes[0] == 4)
		arg1 = ft_strdup("DIR");
	else
		arg1 = ft_strdup("NO ARG");

	if (argument_sizes[1] == 1)
		arg2 = ft_strdup("REG");
	else if (argument_sizes[1] == 2)
		arg2 = ft_strdup("IND");
	else if (argument_sizes[1] == 4)
		arg2 = ft_strdup("DIR");
	else
		arg2 = ft_strdup("NO ARG");

	if (argument_sizes[2] == 1)
		arg3 = ft_strdup("REG");
	else if (argument_sizes[2] == 2)
		arg3 = ft_strdup("IND");
	else if (argument_sizes[2] == 4)
		arg3 = ft_strdup("DIR");
	else
		arg3 = ft_strdup("NO ARG");

	ft_printf("ARG 1 : %s, ARG 2 : %s, ARG 3: %s\n", arg1, arg2, arg3);
/*
**	FIN DEBUG VERIFICATION
*/
	return (argument_sizes);
}
