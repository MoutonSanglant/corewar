/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:05:02 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/30 16:53:09 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		comment_error(void)
{
	ft_printf("Champion comment too long (Max length %i)", COMMENT_LENGTH);
	exit(EXIT_FAILURE);
}

void		name_error(void)
{
	ft_printf("Champion name too long (Max length %i)", PROG_NAME_LENGTH);
	exit(EXIT_FAILURE);
}

int		error(char *str, int errno)
{
	char			*s;
	unsigned int	i;

	s = str;
	i = 0;
	while (*s++)
		i++;
	write(1, str, i);
	return (errno);
}
