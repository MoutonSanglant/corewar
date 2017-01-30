/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <akopera@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:48:28 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/30 18:10:11 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			main(int ac, char **av)
{
	t_flags		flags;

	parse_arguments(ac, av, &flags);
	if (flags & FLAG_COLOR)
		ft_putstr("\033[33m");
	if (flags & FLAG_JOHNY)
		ft_putendl("Johny be good !");
	if (flags & FLAG_OUTPUT)
		ft_putendl("example output");
	if (ac != 2)
		return (USAGE);
	convert_file(av[1]);
	return (0);
}
