/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 19:05:42 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/21 07:45:56 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "asm.h"

void			write_prog_size(int fd)
{
	off_t	cur;
	off_t	end;
	int		size[1];

	cur = lseek(fd, 0, SEEK_CUR);
	end = lseek(fd, 0, SEEK_END);
	size[0] = end - lseek(fd, sizeof(header_t), SEEK_SET);
	lseek(fd, 8 + PROG_NAME_LENGTH, SEEK_SET);
	write(fd, (char*)size + 3, 1);
	write(fd, (char*)size + 2, 1);
	write(fd, (char*)size + 1, 1);
	write(fd, (char*)size, 1);
	lseek(fd, cur, SEEK_SET);
}

void			write_arg(int fd, int *nb, int byte_to_write)
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
			i++;
			if ((*arg)[i] == ' ')
				i++;
			*arg = &((*arg)[i]);
			return ;
		}
		i++;
	}
	*arg = &((*arg)[i]);
}

int				get_arg(char **arg, int *nb)
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
		return (DIR_SIZE);
	}
	else
	{
		*nb = ft_atoi(*arg);
		push_next_arg(arg);
		return (IND_SIZE);
	}
}
