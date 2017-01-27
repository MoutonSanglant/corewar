/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:24:20 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/27 18:32:58 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// VNOON POUR LES CORRECTIONS <3

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

# define OPTIONS_COUNT	4

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
# define ERR_CHAMP_FILE_TOO_BIG "code is too large"
# define ERR_PROG_SIZE "has a code size that differ from what its header says"

# define STR_PLAYER_SUM "* Player %i, weighing %i bytes, \"%s\", (\"%s\") !\n"
# define STR_PLAYER_WIN "le joueur %i(%s) a gagne\n"
# define STR_LIVE_EXEC "un processus dit que le joueur %i(%s) est en vie\n"

typedef enum	e_ops
{
	OP_LIVE = 0x1,
	OP_LD = 0x2,
	OP_ST = 0x3,
	OP_ADD = 0x4,
	OP_SUB = 0x5,
	OP_AND = 0x6,
	OP_OR = 0x7,
	OP_XOR = 0x8,
	OP_ZJMP = 0x9,
	OP_LDI = 0xa,
	OP_STI = 0xb,
	OP_FORK = 0xc,
	OP_LLD = 0xd,
	OP_LLDI = 0xe,
	OP_LFORK = 0xf,
	OP_AFF = 0x10
}				t_ops;


typedef enum	e_flags
{
	FLAG_NONE = 0x0,
	FLAG_DUMP = 0x1,
	FLAG_VERB = 0x2,
	FLAG_NUMB = 0x4,
	FLAG_NCUR = 0x8
}				t_flags;

typedef struct	s_option
{
	char	*s;
	t_flags	f;
	char	c;
}				t_option;

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
	char	*next_op;
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
void	parse_arguments(int argc, char **argv, t_flags *flags);

/* =============================== errors.c ================================= */
void	error(int errno, char *str);
void	error_max_size(char *path, int size);

/* ================================ read.c ================================== */
void	read_champion(char *av, int number);

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
int		*get_argument_sizes(char octet_codage, int opcode, t_player *player);

/* ============================ bytecode_parser.c ============================= */
void	parse_bytecode(t_player *player);



/* ============================ op_functions_1.c ============================= */
void	live_op(t_player *player);
void	ld_op(t_player *player);
void	st_op(t_player *player);
void	add_op(t_player *player);
void	sub_op(t_player *player);
void	and_op(t_player *player);
void	or_op(t_player *player);
void	xor_op(t_player *player);
void	zjmp_op(t_player *player);
void	ldi_op(t_player *player);
void	sti_op(t_player *player);
void	fork_op(t_player *player);
void	lld_op(t_player *player);
void	lldi_op(t_player *player);
void	lfork_op(t_player *player);
void	aff_op(t_player *player);

#endif
