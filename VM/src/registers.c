/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:14:49 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/13 19:28:40 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		read_register(t_registry *reg, int idx)
{
	int val;

	swap_endianess((char *)&val, (char *)&reg[idx], REG_SIZE);
	return(val);
}

void	write_register(t_registry *reg, int idx, char *value_ptr)
{
	swap_endianess((char *)&reg[idx], value_ptr, REG_SIZE);
}
