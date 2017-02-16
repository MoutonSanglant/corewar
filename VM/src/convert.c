/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:10:39 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/16 19:48:23 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>

void	swap_endianess(char *dst, char *value, size_t type_size)
{
	int	i;

	i = type_size - 1;
	while (i >= 0)
	{
		dst[i] = value[type_size - (i + 1)];
		i--;
	}
}
