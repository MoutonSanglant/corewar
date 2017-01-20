/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 19:05:42 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/20 18:23:03 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "asm.h"

static void		init_env(header_t *env, char *arg)
{
	*env = (header_t)malloc(sizeof(header_t));
	if (!(*env))
		memory_error();
	(*env)->magic = COREWAR_EXEC_MAGIC;
	(*env)->prog_name = ft_strcpy((*env)->prog_name, arg);
	(*env)->prog_size = ;
	(*env)->comment = ;

}

void			name_fn(int fd, char *arg)
{
	header_t env;

	init_env(&env, arg);
}

void live_fn(int fd, char **split)
{
	(void)fd;
	(void)split;
}
