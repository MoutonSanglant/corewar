/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 19:05:42 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/21 22:16:25 by lalves           ###   ########.fr       */
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
		pad = 4 - ((COMMENT_LENGTH + 1) % 4);
	pad += COMMENT_LENGTH + 1 - i;
	str = ft_strnew(pad);
	write(fd, str, pad);
	ft_strdel(&str);
	return (1);
}

int			live_fn(t_env *env, char *arg, char opcode)
{
	int		nb[1];

	if (*(arg + 1) == LABEL_CHAR)
		nb[0] = save_used_label(arg, env, 1, 0);
	else
		nb[0] = ft_atoi(arg + 1);
	write(env->dst_fd, &opcode, 1);
	write(env->dst_fd, ((char*)nb) + 3, 1);
	write(env->dst_fd, ((char*)nb) + 2, 1);
	write(env->dst_fd, ((char*)nb) + 1, 1);
	write(env->dst_fd, (char*)nb, 1);
	return (1);
}

int			ld_fn(t_env *env, char *arg, char opcode)
{
	int		nb;
	int		byte_to_write;

	write(env->dst_fd, &opcode, 1);
	write_ocp(env->dst_fd, arg, 2);
	while (*arg)
	{
		byte_to_write = get_arg(&arg, &nb, env, 0);
		write_arg(env->dst_fd, &nb, byte_to_write - 1);
	}
	return (1);
}

int			st_fn(t_env *env, char *arg, char opcode)
{
	int		nb;
	int		byte_to_write;

	write(env->dst_fd, &opcode, 1);
	write_ocp(env->dst_fd, arg, 2);
	while (*arg)
	{
		byte_to_write = get_arg(&arg, &nb, env, 0);
		write_arg(env->dst_fd, &nb, byte_to_write - 1);
	}
	return (1);
}
