/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:24:20 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/07 18:19:31 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// VNOON POUR LES CORRECTIONS <3

#ifndef COREWAR_H

# define COREWAR_H

# include <op.h>
# include <libft.h>
# include <libftprintf.h>

# define BUFF_SIZE 1024

# define NAME "corewar"
# define USAGE_DUMP "[-d nbr_cycles]"
# define USAGE_CHAMP "[[-n number] champion1.cor] ..."

# define OPTIONS_COUNT	4

# define ERRNO_USAGE	0x1
# define ERRNO_OPEN		0x2
# define ERRNO_EMPTY	0x3
# define ERRNO_HEADER	0x4
# define ERRNO_CHAMP_FILE_TOO_SMALL		0x5
# define ERRNO_CHAMP_FILE_TOO_BIG		0x6
# define ERRNO_PROG_SIZE		0x7
# define ERRNO_CHAMP_NBR		0x8
# define ERRNO_MEMORY			0x9

# define ERR_OPEN "Could not open file" // v
# define ERR_EMPTY "is empty" // v (size)

// verified:
# define ERR_HEADER "has an invalid header"
# define ERR_CHAMP_FILE_TOO_SMALL "is too small to be a champion"
# define ERR_CHAMP_FILE_TOO_BIG "code is too large"
# define ERR_PROG_SIZE "has a code size that differ from what its header says"
# define ERR_CHAMP_NBR "same number cannot be used for different champions"
# define ERR_MEMORY "memory allocation error (%s)\n"
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

typedef struct	s_op_arg
{
	char		*arg;
	size_t		size;
	t_arg_type	type;
	int			value;
}				t_op_arg;

typedef char	t_registry[REG_SIZE];

typedef struct	s_proc
{
	t_registry	reg[REG_NUMBER];
	char		*pc;
	int			carry; // 0 ou 1
	int			wait;
	int			live;
}				t_proc;

typedef struct	s_player
{
	char	*name;
	char	*comment;
	char	*bytecode;
	//char	*next_op;
	int		prog_size;
	char	number;
	char	id;
	//int		idle;
	//t_proc	*champ_proc;
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
	t_proc			*process;
	void			*extra;
	int				process_count;
	int				player_count;
	t_cycle_infos	cycle_infos;
	t_flags			flags;
	int				dump_cycle;
}				t_corewar;

typedef struct	s_op
{
	const char	*name;
	int			arg_number;
	t_arg_type	arg_type[3];
	int			value;
	int			cycles;
	const char	*description;
	int			ocp;
	int			dir_short;
}				t_op;

/*
**	GLOBALS
*/
extern t_corewar	g_corewar;
extern t_op			g_op_tab[17];

/* ================================ init.c ================================== */
void	init_bonus();

/* ============================== arguments.c =============================== */
void	parse_arguments(int argc, char **argv, t_flags *flags);

/* =============================== errors.c ================================= */
void	error(int errno, char *str);
void	error_max_size(char *path, int size);

/* ================================ read.c ================================== */
void	read_champion(char *av, int number);


/* =============================== convert.c ================================ */
void	swap_endianess(char *dst, char *value, size_t type_size);

/* =============================== players.c ================================ */
void	set_players_regs(t_player *players);
void	load_players_in_mem(char *arena, t_player *players);

/* ================================= dump.c ================================= */
void	dump_memory(char *memory);

/* ================================== vm.c ================================== */
void	run_vm();

/* ================================ cycles.c ================================ */
void	cycle_handler();

/* ============================ get_arg_sizes.c ============================= */
size_t	get_argument_op(t_proc *proc, int opcode, t_op_arg args[3]);

/* ============================ bytecode_parser.c =========================== */
void	parse_bytecode(t_proc *proc);

/* =============================== register.c =============================== */
int		read_register(t_registry *reg, int idx);
int		store_register(t_registry *reg, int idx, char *value_ptr);
int		copy_register(t_registry *reg, int dst_idx, int src_idx);
int		write_register(t_registry *reg, int idx, char *pc);

/* ============================ op_functions_1.c ============================ */

void	live_op(t_proc *proc, t_op_arg args[3]);
void	ld_op(t_proc *proc, t_op_arg args[3]);
void	st_op(t_proc *proc, t_op_arg args[3]);
void	add_op(t_proc *proc, t_op_arg args[3]);
void	sub_op(t_proc *proc, t_op_arg args[3]);
void	and_op(t_proc *proc, t_op_arg args[3]);
void	or_op(t_proc *proc, t_op_arg args[3]);
void	xor_op(t_proc *proc, t_op_arg args[3]);
void	zjmp_op(t_proc *proc, t_op_arg args[3]);
void	ldi_op(t_proc *proc, t_op_arg args[3]);
void	sti_op(t_proc *proc, t_op_arg args[3]);
void	fork_op(t_proc *proc, t_op_arg args[3]);
void	lld_op(t_proc *proc, t_op_arg args[3]);
void	lldi_op(t_proc *proc, t_op_arg args[3]);
void	lfork_op(t_proc *proc, t_op_arg args[3]);
void	aff_op(t_proc *proc, t_op_arg args[3]);

/* =============================== read_arg.c= ============================== */
int		**read_arg(t_player *player, int *arg_sizes);

/* =============================== process.c ================================ */
t_proc	*process_create(char *pc);
void	process_fork(t_proc *process, int offset);
int		process_op(t_proc *proc, t_op *op);
char	*process_move(t_proc *proc, int offset);
void	process_kill(t_proc *proc, int idx);

#endif
