/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:14:49 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/14 21:37:55 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_registry	*get_register(t_registry *reg, int idx)
{
	if (idx < 1 || idx > REG_NUMBER)
	{
		g_corewar.reg_error = 1;
		return (NULL);
	}
	return (&reg[idx - 1]);
}

/*
** idx sera toujours une valeur comprise entre 1 et REG_NUMBER
*/

int			read_register(t_registry *reg, int idx)
{
	t_registry	*r;
	int			value;

	if ((r = get_register(reg, idx)) == NULL)
		return (0);
	swap_endianess((char *)&value, (char *)r, REG_SIZE);
	return (value);
}

int			store_register(t_registry *reg, int idx, char *value_ptr)
{
	t_registry	*r;

	if ((r = get_register(reg, idx)) == NULL)
		return (0);
	swap_endianess((char *)r, value_ptr, REG_SIZE);
	return (1);
}

int			store_addr_register(t_registry *reg, int idx, char *pc)
{
	t_registry	*r;

	if ((r = get_register(reg, idx)) == NULL)
		return (0);
	read_range((char *)r, pc, REG_SIZE);
	return (1);
}


int			write_register(t_registry *reg, int idx, char *pc)
{
	t_registry	*r;

	if ((r = get_register(reg, idx)) == NULL)
		return (0);
	write_range((char *)r, pc, REG_SIZE, read_register(reg, 1));
	return (1);
}

int			copy_register(t_registry *reg, int dst_idx, int src_idx)
{
	t_registry	*r1;
	t_registry	*r2;

	if ((r1 = get_register(reg, dst_idx)) == NULL
			|| (r2 = get_register(reg, src_idx)) == NULL)
		return (0);
	ft_memcpy((void *)r1, (void *)r2, REG_SIZE);
	return (1);
}
