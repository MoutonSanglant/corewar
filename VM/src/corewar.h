/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:24:20 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/25 17:56:32 by akopera          ###   ########.fr       */
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
# define ERRNO_CHAMP_FILE_TOO_SMALL		0x5
# define ERRNO_CHAMP_FILE_TOO_BIG		0x6
# define ERRNO_PROG_SIZE		0x7

# define ERR_OPEN "Could not open file" // v
# define ERR_EMPTY "Empty file" // v (size)

// verified:
# define ERR_HEADER "has an invalid header"
# define ERR_CHAMP_FILE_TOO_SMALL "is too small to be a champion"
# define ERR_CHAMP_FILE_TOO_BIG "is too ??????????????????"
# define ERR_PROG_SIZE "has a code size that differ from what its header says"

# define STR_PLAYER_SUM "* Player %i, weighing %i bytes, \"%s\", (\"%s\") !\n"
# define STR_PLAYER_WIN "le joueur %i(%s) a gagne\n"
# define STR_LIVE_EXEC "un processus dit que le joueur %i(%s) est en vie\n"

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
	char	*bytecode;
	int		prog_size;
	char	number;
	t_proc	champ_proc;
}				t_player;

typedef void (*print_fn)(char *str);

typedef struct	s_corewar
{
	t_player	*players;
	print_fn	print_screen;
	void		*extra;
	int			player_count;
}				t_corewar;

/*
**	GLOBALS
*/
extern t_corewar	g_corewar;

/* ================================ init.c ================================== */
void	init();
void	release();

/* ============================== arguments.c =============================== */
int		parse_arguments(int argc, char **argv, t_flags *flags);

/* =============================== errors.c ================================= */
void	error(int errno, char *str);

/* ================================ read.c ================================== */
void	read_champions(int count, char **av);

/* ================================ bytes.c ================================= */
int		bytes_to_int(char *b);

/* =============================== players.c ================================ */
void	set_players_regs(t_player *players);
void	load_players_in_mem(int players_nb, char terrain[MEM_SIZE], t_player *players);


/* ================================== vm.c ================================== */
void	run_vm(int players_count, t_player *players);


/* ============================== registers.c =============================== */
void	set_reg(t_registry reg, char *value, size_t type_size);

/* ============================ get_arg_sizes.c ============================= */
int		*get_argument_sizes(char octet_codage);

#endif
