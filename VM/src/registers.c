/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:14:49 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/14 13:02:53 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** idx sera toujours une valeur comprise entre 1 et REG_NUMBER
*/
int		read_register(t_registry *reg, int idx)
{
	int val;

	if (idx < 1 || idx >= REG_NUMBER)
		return (-1);
	swap_endianess((char *)&val, (char *)&reg[idx - 1], REG_SIZE);
	return (val);
}

int		store_register(t_registry *reg, int idx, char *value_ptr)
{
	if (idx < 1 || idx >= REG_NUMBER)
		return (-1);
	swap_endianess((char *)&reg[idx - 1], value_ptr, REG_SIZE);
	return (0);
}

int		write_register(t_registry *reg, int idx, char *pc)
{
	if (idx < 1 || idx >= REG_NUMBER)
		return (-1);
	ft_memcpy((void*)pc, (void*)reg[idx - 1], REG_SIZE);
	return (0);
}

int		copy_register(t_registry *reg, int dst_idx, int src_idx)
{
	t_registry	*dst;
	t_registry	*src;
	int			i;

	if (dst_idx < 1 || dst_idx >= REG_NUMBER
			|| src_idx < 1 || src_idx >= REG_NUMBER)
		return (-1);
	dst = &reg[dst_idx - 1];
	src = &reg[src_idx - 1];
	i = 0;
	while (i < REG_SIZE)
		(*dst)[i] = (*src)[i];
	return (0);
}
