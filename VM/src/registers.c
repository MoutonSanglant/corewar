/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:56:22 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/26 17:15:02 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_reg(t_registry reg, char *value, size_t type_size)
{
	int	i;

	i = REG_SIZE - 1;
	while (i >= 0)
	{
		reg[i] = value[type_size - (i + 1)];
		i--;
	}
}

// si type_size > REG_SIZE
//
// ex (4, 2)
// ff 01 02 a3
// 02 a3
//
// si REG_SIZE > type_size
//
// ex (8, 4)
// ff 01 02 a3
// 00 00 00 00 ff 01 02 a3
