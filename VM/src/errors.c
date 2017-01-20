/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:30:12 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/20 17:26:41 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "corewar.h"

int		error(char *str, int errno)
{
	char			*s;
	unsigned int	i;

	i = 0;
	s = str;
	while (*s++)
		i++;
	write(1, str, i);
	return (errno);
}

int		error_usage()
{
	ft_printf("usage: corewar %s %s\n", USAGE_DUMP, USAGE_CHAMP);
	return (1);
}
