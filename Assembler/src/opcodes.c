/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 19:05:42 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/25 21:04:34 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "asm.h"

void			name_fn(int fd, char *arg, char c)
{
	size_t	i;

	i = ft_strlen(arg);
	if (i > PROG_NAME_LENGTH)
		name_error(); // Le nom du champion depasse la taille max
	ft_putstr_fd(arg, fd);
	while (i < PROG_NAME_LENGTH + 8) // +4 padding ? et + 4 pour prog_size
	{
		write(fd, &c, 1);
		i++;
	}
}

void			comment_fn(int fd, char *arg, char c)
{
	size_t	i;

	i = ft_strlen(arg);
	if (i > COMMENT_LENGTH)
		comment_error(); // Le commentaire depasse la taille max
	ft_putstr_fd(arg, fd);
	while (i < COMMENT_LENGTH + 4) // +4 padding ?
	{
		write(fd, &c, 1);
		i++;
	}
}

void			live_fn(int fd, char *arg, char opcode)
{
	int		nb[1];

	nb[0] = ft_atoi(arg + 1);
	write(fd, &opcode, 1);
	write(fd, ((char*)nb) + 3, 1);
	write(fd, ((char*)nb) + 2, 1);
	write(fd, ((char*)nb) + 1, 1);
	write(fd, (char*)nb, 1);
}

void			ld_fn(int fd, char *arg, char opcode)
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
}

void			st_fn(int fd, char *arg, char opcode)
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
}
