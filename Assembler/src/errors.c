/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:05:02 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/25 18:14:40 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		comment_error(void)
{
	ft_putendl("La commentaire du champion depasse la taille maximum");
	exit(EXIT_FAILURE);
}

void		name_error(void)
{
	ft_putendl("Le nom du champion depasse la taille maximum");
	exit(EXIT_FAILURE);
}

void		memory_error(void)
{
	ft_putendl_fd("memory error", 2);
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
