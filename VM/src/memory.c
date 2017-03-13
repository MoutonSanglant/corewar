/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 02:03:15 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/13 02:10:34 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	read_byte(char *addr)
{
	int		overflow;

	if ((overflow = addr - (g_corewar.cycle_infos.arena + MEM_SIZE)) >= 0)
		return (g_corewar.cycle_infos.arena[overflow]);
	return (*addr);
}
