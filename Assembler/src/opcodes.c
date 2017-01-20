/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 19:05:42 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/20 21:45:47 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "asm.h"

void			name_fn(int fd, char *arg)
{
	size_t	i;
	char	c;

	i = ft_strlen(arg);
	c = 0;
	if (i > PROG_NAME_LENGTH)
		error_name(); // Le nom du champion depasse la taille max
	ft_putstr_fd(arg, fd);
	while (i < PROG_NAME_LENGTH + 4)
	{
		write(fd, &c, 1);
		i++;
	}
}

void			comment_fn(int fd, char *arg)
{
	size_t	i;
	char	c;

	i = ft_strlen(arg);
	c = 0;
	if (i > COMMENT_LENGTH)
		error_comment(); // Le commentaire depasse la taille max
	ft_putstr_fd(arg, fd);
	while (i < COMMENT_LENGTH)
	{
		write(fd, &c, 1);
		i++;
	}
}

void			live_fn(int fd, char *arg)
{
	int		nb[1];

	arg++;
	nb[0] = ft_atoi(arg);
	write(fd, (char*)(nb + 3), 1);
	write(fd, (char*)(nb + 2), 1);
	write(fd, (char*)(nb + 1), 1);
	write(fd, (char*)nb, 1);
}

void			ld_fn(int fd, char *arg)
{

}
