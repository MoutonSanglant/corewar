/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 19:05:42 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/18 18:14:35 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "asm.h"

void name_fn(int fd, char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		write(fd, split[i], ft_strlen(split[i]));
		if (split[i + 1])
			write(fd, " ", 1);
		i++;
	}
}

void live_fn(int fd, char **split)
{
	(void)fd;
	(void)split;
}
