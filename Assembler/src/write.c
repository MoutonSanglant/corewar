/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 19:05:42 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/25 21:04:04 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "asm.h"

void		write_arg(int fd, int *nb, int byte_to_write)
{
	while (byte_to_write >= 0)
	{
		write(fd, ((char*)nb) + byte_to_write, 1);
		byte_to_write--;
	}
}

static void		push_next_arg(char **arg)
{
	int i;

	i = 0;
	while ((*arg)[i])
	{
		if ((*arg)[i] == SEPARATOR_CHAR)
		{
			i += 2;
			*arg = &((*arg)[i]);
			return;
		}
		i++;
	}
	*arg = &((*arg)[i]);
}

int			get_arg(char **arg, int *nb)
{
	int i;

	i = 0;
	if ((*arg)[i] == 'r')
	{
		*nb = ft_atoi((*arg) + 1);
		push_next_arg(arg);
		return (1);
	}
	else if ((*arg)[i] == DIRECT_CHAR)
	{
		*nb = ft_atoi((*arg) + 1);
		push_next_arg(arg);
		return (4);
	}
	else
	{
		*nb = ft_atoi(*arg);
		push_next_arg(arg);
		return (2);
	}
}
