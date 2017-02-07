/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:24:20 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/06 19:31:00 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// VNOON POUR LES CORRECTIONS <3

#ifndef COREWAR_H

#define COREWAR_H

# include <op.h>
# include <libft.h>
# include <libftprintf.h>

//# ifdef BONUS
//#  include "bonus/bonus.h"
//# endif

# define BUFF_SIZE 1024

# define NAME "corewar"
# define USAGE_DUMP "[-d nbr_cycles]"
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
# define ERR_EMPTY "is empty" // v (size)

// verified:
# define ERR_HEADER "has an invalid header"
# define ERR_CHAMP_FILE_TOO_SMALL "is too small to be a champion"
# define ERR_CHAMP_FILE_TOO_BIG "code is too large"
# define ERR_PROG_SIZE "has a code size that differ from what its header says"
# define ERR_UNDEFINED "undefined error"

# define ERR_TOO_MANY "Too many champions"

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
	char		*pc;
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
	int		idle;
	t_proc	*champ_proc;
}				t_player;

typedef enum	e_byte_flag
{
	BYTE_POINTER = 0x1,
	BYTE_WRITE = 0x2
}				t_byte_flag;

typedef struct	s_byte_infos
{
	char		number;
	t_byte_flag	byte_flag;
}				t_byte_infos;

typedef struct	s_cycle_infos
{
	unsigned int	cps;
	unsigned int	count;
	unsigned int	cycle_to_die;
	unsigned int	cycle_delta;
	unsigned int	nbr_live;
	unsigned int	checks_count;
	unsigned int	max_checks;
	unsigned int	running_proc;
	t_byte_infos	byte_infos[MEM_SIZE];
	char			*arena;
}				t_cycle_infos;

typedef struct	s_corewar
{
	t_player		*players;
	void			*extra;
	int				player_count;
	t_cycle_infos	cycle_infos;
	t_flags			flags;
	int				dump_cycle;
}				t_corewar;


/*
**	GLOBALS
*/
extern t_corewar	g_corewar;

/* ================================ init.c ================================== */
void	init_bonus();

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
void	load_players_in_mem(int players_nb, char *arena, t_player *players);


/* ================================== vm.c ================================== */
void	run_vm(int players_count, t_player *players);

/* ================================ cycles.c ================================ */
void	cycle_handler(t_player *players);
int		check_idle(t_player *player, int idle_time);

/* ============================== registers.c =============================== */
void	set_reg(t_registry reg, char *value, size_t type_size);

/* ============================ get_arg_sizes.c ============================= */
int		*get_argument_sizes(char octet_codage, int opcode, t_player *player);

/* ============================ bytecode_parser.c =========================== */
void	parse_bytecode(t_player *player);


/* ============================ run_processes.c= ============================ */
void	run_processes(t_cycle_infos *infos, t_player *players);

/* ============================ op_functions_1.c ============================ */
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

/* =============================== read_arg.c= ============================== */
int		**read_arg(t_player *player, int *arg_sizes);

#endif
