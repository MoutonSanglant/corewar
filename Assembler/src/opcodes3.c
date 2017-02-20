/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 19:05:42 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/27 20:00:30 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "asm.h"

int			zjmp_fn(int fd, char *arg, char opcode)
{
	int		nb;
	int		byte_to_write;

	write(fd, &opcode, 1);
	while (*arg)
	{
		byte_to_write = get_arg(&arg, &nb);
		if (byte_to_write == DIR_SIZE)
			byte_to_write = IND_SIZE;
		write_arg(fd, &nb, byte_to_write - 1);
	}
	return (1);
}


int			ldi_fn(int fd, char *arg, char opcode)
{
	int		nb;
	int		byte_to_write;

	write(fd, &opcode, 1);
	write_ocp(fd, arg, 3);
	while (*arg)
	{
		byte_to_write = get_arg(&arg, &nb);
		if (byte_to_write == DIR_SIZE)
			byte_to_write = IND_SIZE;
		write_arg(fd, &nb, byte_to_write - 1);
	}
	return (1);
}

int			sti_fn(int fd, char *arg, char opcode)
{
	int		nb;
	int		byte_to_write;

	write(fd, &opcode, 1);
	write_ocp(fd, arg, 3);
	while (*arg)
	{
		byte_to_write = get_arg(&arg, &nb);
		if (byte_to_write == DIR_SIZE)
			byte_to_write = IND_SIZE;
		write_arg(fd, &nb, byte_to_write - 1);
	}
	return (1);
}

int			fork_fn(int fd, char *arg, char opcode)
{
	int		nb;
	int		byte_to_write;

	write(fd, &opcode, 1);
	while (*arg)
	{
		byte_to_write = get_arg(&arg, &nb);
		if (byte_to_write == DIR_SIZE)
			byte_to_write = IND_SIZE;
		write_arg(fd, &nb, byte_to_write - 1);
	}
	return (1);
}

int			lld_fn(int fd, char *arg, char opcode)
{
	int		nb;
	int		byte_to_write;

	write(fd, &opcode, 1);
	write_ocp(fd, arg, 2);
	while (*arg)
	{
		byte_to_write = get_arg(&arg, &nb);
		write_arg(fd, &nb, byte_to_write - 1);
	}
	return (1);
}
