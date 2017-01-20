/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:30:12 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/20 20:29:38 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "corewar.h"

// ASM
// On folder:
// Read..
// Syntax error at...
//
// Lexical error at...
//
//
// folder:
// Read..
//

static void		usage()
{
	ft_eprintf("usage: corewar %s %s\n", USAGE_DUMP, USAGE_CHAMP);
	exit(ERRNO_USAGE);
}

void			error(int errno, char *str)
{
	if (errno == ERRNO_USAGE)
		usage();
	write(2, "Error: ", 7);
	if (errno == ERRNO_OPEN)
		write(2, str, ft_strlen(str));
	if (errno == ERRNO_EMPTY)
		write(2, str, ft_strlen(str));
	if (errno == ERRNO_HEADER)
		ft_eprintf(ERR_HEADER, str);
	if (errno == ERRNO_SIZE)
		ft_eprintf(ERR_SIZE, str);
	write(2, "\n", 1);
	exit (errno);
}
