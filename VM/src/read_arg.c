/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:36:33 by akopera           #+#    #+#             */
/*   Updated: 2017/02/06 20:32:56 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		*ft_atoi_base(char *str, int size)
{
	int	*res;
	int nb;
	int mult;
	int i;

	i = size - 1;
	ft_printf("\nSize = %d", size);
	while (i >= 0)
	{
		ft_printf("\n(int)Char [%i]  : %d\n", i, (int)str[i]);
		i--;
	}
	res = (int*)malloc(sizeof(int));
	nb = 0;
	mult = 1;
	while (size >= 0)
	{
		if (ft_isalpha(str[size]))
			nb += (str[size] - 87) * mult;
		else
			nb += (str[size] - '0') * mult;
		size--;
		mult *= 16;
	}
	res = &nb;
	return (res);
}

/*
static int		*convert_arg(char *bytecode, int size)
{
	char	*tmp;
	int		i;

	i = size * 2;
	tmp = (char*)malloc(sizeof(char) * (size * 2) + 1);
	tmp[i] = 0;
	i--;
	while (i >= 0)
	{
		tmp[i] = bytecode[i] + '0';
		i--;
	}
	return (ft_atoi_base(tmp, size * 2 - 1));
}
*/
int		**read_arg(t_player *player, int	*arg_sizes)
{
	int	**arg_values;

	arg_values = (int**)malloc(sizeof(int*) * 3);

	arg_values[0] = ft_atoi_base(player->bytecode + 2, arg_sizes[0]);
	if (arg_sizes[1])
		arg_values[1] = ft_atoi_base(player->bytecode + 2 + arg_sizes[0], arg_sizes[1]);
	else
		arg_values[1] = NULL;
	ft_printf("\nsize = %i\n", arg_sizes[2]);
	if (arg_sizes[2])
		arg_values[2] = ft_atoi_base(player->bytecode + 2 + arg_sizes[0] + arg_sizes[1], arg_sizes[2]);
	else
	{
		arg_values[2] = NULL;
	}
		ft_printf("ONVAMANGER\n");
//	ft_printf("\nARG VALUE: ARG 1 %d\n, ARG 2 : %d\n, ARG 3 : %d \n", *arg_values[0], *arg_values[1], *arg_values[2]);
		return (arg_values);
}
