/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:24:20 by tdefresn          #+#    #+#             */
/*   Updated: 2016/10/13 14:24:20 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

#define COREWAR_H

# include <op.h>
# include <libft.h>
# include <libftprintf.h>

# ifdef BONUS
#  include "bonus/bonus.h"
# endif

# define BUFF_SIZE 1024

# define NAME "corewar"
# define USAGE_DUMP "[-dump nbr_cycles]"
# define USAGE_CHAMP "[-[-n number] champion1.cor] ..."

# define ERRNO_USAGE	0x1
# define ERRNO_OPEN		0x2
# define ERRNO_EMPTY	0x3
# define ERRNO_HEADER	0x4
# define ERRNO_SIZE		0x5

# define ERR_OPEN "Could not open file" // v
# define ERR_EMPTY "Empty file" // v (size)

// verified:
# define ERR_HEADER "File %s has an invalid header"
# define ERR_SIZE "File %s is too small to be a champion"

# define ARGS_LIST_SIZE 3

typedef enum	e_flags
{
	FLAG_OUTPUT = 0x1,
	FLAG_JOHNY = 0x2,
	FLAG_COLOR = 0x4
}				t_flags;

typedef struct	s_args
{
	char	*string;
	t_flags	flag;
	char	c;
}				t_args;

typedef char t_registry[REG_SIZE];

typedef struct	s_proc
{
	t_registry	reg[REG_NUMBER];
	void		*pc;
	int			carry; // 0 ou 1
}				t_proc;

typedef struct	s_player
{
	char	*name;
	char	*comment;
	int		number;
}				t_player;

typedef struct	s_corewar
{
	t_player	*players;
	int			player_count;
}				t_corewar;

/*
**	GLOBALS
*/
extern t_corewar	g_corewar;

/* ================================ init.c ================================== */
void	init();

/* ============================== arguments.c =============================== */
int		parse_arguments(int argc, char **argv, t_flags *flags);

/* =============================== errors.c ================================= */
void	error(int errno, char *str);

/* ================================ read.c ================================== */
void	read_champions(int count, char **av);

/* ================================ bytes.c ================================= */
int		bytes_to_int(char *b);

#endif
