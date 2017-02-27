/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:24:20 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/17 20:34:53 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** VNOON POUR LES CORRECTIONS <3
*/

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

# define ERR_OPEN "Could not open file"
# define ERR_EMPTY "is empty"

# define ERR_HEADER "has an invalid header"
# define ERR_CHAMP_FILE_TOO_SMALL "is too small to be a champion"
# define ERR_CHAMP_FILE_TOO_BIG "code is too large"
# define ERR_PROG_SIZE "has a code size that differ from what its header says"
# define ERR_CHAMP_NBR "same number cannot be used for different champions"
# define ERR_MEMORY "memory allocation error (%s)\n"
# define ERR_UNDEFINED "undefined error"

# define ERR_TOO_MANY "Too many champions"

# define STR_PLAYER_SUM "* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n"
# define STR_PLAYER_WIN "le joueur %i (%s) a gagne\n"
# define STR_LIVE_EXEC "un processus dit que le joueur %i(%s) est en vie\n"

typedef enum	e_state
{
	STATE_PAUSED,
	STATE_RUNNING,
	STATE_DONE
}				t_state;

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
	t_registry		reg[REG_NUMBER];
	t_op			*op;
	char			*pc;
	char			opc;
	int				carry;
	int				wait;
	int				live;
	unsigned int	id;
}				t_proc;

typedef struct	s_player
{
	char	*name;
	char	*comment;
	char	*bytecode;
	int		prog_size;
	int		number;
	char	id;
	int		last_live;
	int		current_lives;
}				t_player;

typedef struct	s_byte_infos
{
	char		number;
	char		live;
	char		pc;
	char		op;
}				t_byte_infos;

typedef struct	s_cycle_infos
{
	t_byte_infos	byte_infos[MEM_SIZE];
	int				aff[4];
	t_player		*winner;
	char			*arena;
	int				last_live;
	unsigned int	speed;
	unsigned int	cps;
	unsigned int	count;
	unsigned int	cycle_to_die;
	unsigned int	cycle_delta;
	unsigned int	nbr_live;
	unsigned int	checks_count;
	unsigned int	running_proc;
}				t_cycle_infos;

typedef struct	s_corewar
{
	t_player		*players;
	t_proc			*process;
	void			*extra;
	t_state			state;
	int				process_count;
	int				player_count;
	t_cycle_infos	cycle_infos;
	t_flags			flags;
	int				dump_cycle;
	int				reg_error;
}				t_corewar;

/*
**	GLOBALS
*/

extern t_corewar	g_corewar;
extern t_op			g_op_tab[17];

/*
** ================================ init.c ==================================
*/

void			init_bonus();

/*
** ============================== arguments.c ===============================
*/

void			parse_arguments(int argc, char **argv, t_flags *flags);

/*
** =============================== errors.c =================================
*/

void			error(int errno, char *str);
void			error_max_size(char *path, int size);

/*
** ================================ read.c ==================================
*/

void			read_champion(char *av, int number);

/*
** =============================== convert.c ================================
*/

void			swap_endianess(char *dst, char *value, size_t type_size);

/*
** =============================== players.c ================================
*/

void			load_players_in_mem(char *arena, t_player *players);
t_player		*find_player(int id);

/*
** ================================= dump.c =================================
*/

void			dump_memory(char *memory);

/*
** ================================== vm.c ==================================
*/

void			run_vm();

/*
** ================================ cycles.c ================================
*/

void			cycle_handler();

/*
** ============================ get_arg_sizes.c =============================
*/

size_t			get_argument_op(t_proc *proc, int opcode, t_op_arg args[3]);

/*
** ============================ bytecode_parser.c ===========================
*/

void			parse_bytecode(t_proc *proc);

/*
** =============================== register.c ===============================
*/
int				read_register(t_registry *reg, int idx);
int				store_addr_register(t_registry *reg, int idx, char *pc);
int				store_register(t_registry *reg, int idx, char *value_ptr);
int				copy_register(t_registry *reg, int dst_idx, int src_idx);
int				write_register(t_registry *reg, char *pc, int idx);

/*
** ============================ op_functions_1.c ============================
*/

void			live_op(t_proc *proc, t_op_arg args[3]);
void			ld_op(t_proc *proc, t_op_arg args[3]);
void			st_op(t_proc *proc, t_op_arg args[3]);
void			add_op(t_proc *proc, t_op_arg args[3]);
void			sub_op(t_proc *proc, t_op_arg args[3]);
void			and_op(t_proc *proc, t_op_arg args[3]);
void			or_op(t_proc *proc, t_op_arg args[3]);
void			xor_op(t_proc *proc, t_op_arg args[3]);
void			zjmp_op(t_proc *proc, t_op_arg args[3]);
void			ldi_op(t_proc *proc, t_op_arg args[3]);
void			sti_op(t_proc *proc, t_op_arg args[3]);
void			fork_op(t_proc *proc, t_op_arg args[3]);
void			lld_op(t_proc *proc, t_op_arg args[3]);
void			lldi_op(t_proc *proc, t_op_arg args[3]);
void			lfork_op(t_proc *proc, t_op_arg args[3]);
void			aff_op(t_proc *proc, t_op_arg args[3]);

/*
**  =============================== read_arg.c ===============================
*/

int				**read_arg(t_player *player, int *arg_sizes);

/*
**  =============================== get_value.c ===============================
*/

int				get_value(t_proc *p, t_op_arg *arg, int	idx, int long_op);

/*
** =============================== process.c ================================
*/

t_proc			*process_create(char *pc, t_proc *proc, int offset);
int				process_op(t_proc *proc);
char			*process_move(t_proc *proc, int offset);
void			process_kill(t_proc *proc, int idx);

#endif
