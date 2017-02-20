/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 19:05:42 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/30 19:16:26 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "asm.h"

int			name_fn(int fd, char *arg)
{
	size_t	i;
	size_t	pad;
	char	*str;

	i = ft_strlen(arg);
	ft_putstr_fd(arg, fd);
	if ((PROG_NAME_LENGTH + 1) % 4)
		pad = 4 - ((PROG_NAME_LENGTH + 1) % 4);
	pad += PROG_NAME_LENGTH + 5 - i;
	str = ft_strnew(pad);
	write(fd, str, pad);
	ft_strdel(&str);
	return (1);
}

int			comment_fn(int fd, char *arg)
{
	size_t	i;
	size_t	pad;
	char	*str;

	i = ft_strlen(arg);
	ft_putstr_fd(arg, fd);
	if ((COMMENT_LENGTH + 1) % 4)
		pad = 4 - ((COMMENT_LENGTH + 1) %4);
	pad += COMMENT_LENGTH + 1 - i;
	str = ft_strnew(pad);
	write(fd, str, pad);
	ft_strdel(&str);
	return (1);
}

int			live_fn(int fd, char *arg, char opcode)
{
	int		nb[1];

	nb[0] = ft_atoi(arg + 1);
	write(fd, &opcode, 1);
	write(fd, ((char*)nb) + 3, 1);
	write(fd, ((char*)nb) + 2, 1);
	write(fd, ((char*)nb) + 1, 1);
	write(fd, (char*)nb, 1);
	return (1);
}

int			ld_fn(int fd, char *arg, char opcode)
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

int			st_fn(int fd, char *arg, char opcode)
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
