/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:30:12 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/25 13:15:59 by tdefresn         ###   ########.fr       */
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
	ft_putstr_fd("Error: ", 2);
	if (errno == ERRNO_OPEN)
		ft_putendl_fd(str, 2);
	if (errno == ERRNO_EMPTY)
		ft_putendl_fd(str, 2);
	if (errno == ERRNO_HEADER)
		ft_eprintf("File %s %s\n", str, ERR_HEADER);
	if (errno == ERRNO_CHAMP_FILE_TOO_SMALL)
		ft_eprintf("File %s %s\n", str, ERR_CHAMP_FILE_TOO_SMALL);
	if (errno == ERRNO_CHAMP_FILE_TOO_BIG)
		ft_eprintf("File %s %s\n", str, ERR_CHAMP_FILE_TOO_BIG);
	if (errno == ERRNO_PROG_SIZE)
		ft_eprintf("File %s %s\n", str, ERR_PROG_SIZE);
	exit (errno);
}
