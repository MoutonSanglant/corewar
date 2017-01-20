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

# define BUFF_SIZE 1024

# define NAME "corewar"
# define USAGE_DUMP "[-dump nbr_cycles]"
# define USAGE_CHAMP "[-[-n number] champion1.cor] ..."

# define USAGE_P2 "[[-n number] champion1.cor] ...\n"
# define ERROR_OPEN error("corewar: Could not open file\n", -2)
# define ERROR_EMPTY_FILE error("corewar: Empty file\n", -3)
# define ERROR_INVALID_FILETYPE error("corewar: Incorrect file type\n", -4)

# define ARGS_LIST_SIZE 3

typedef enum	e_flags
{
	FLAG_OUTPUT = 0x1,
	FLAG_JOHNY = 0x2,
	FLAG_COLOR = 0x4
}
t_flags;

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
	int		number;
}				t_player;

/* ============================== arguments.c =============================== */
int		parse_arguments(int argc, char **argv, t_flags *flags);

/* =============================== errors.c ================================= */
int		error(char *str, int errno);
int		error_usage();

/* ================================ read.c ================================== */
void	read_binary(char *path);

/* ================================ bytes.c ================================= */
int		bytes_to_int(char *b);

#endif
