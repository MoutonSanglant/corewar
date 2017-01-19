/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 18:00:16 by lalves            #+#    #+#             */
/*   Updated: 2017/01/19 20:14:34 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

#define ASM_H

# include <op.h>
# include <libft.h>
# include <libftprintf.h>

# define USAGE error("Usage: ./asm [-a] mon_champion.s\n", -1)
# define ERROR_OPEN_SRC error("asm: Could not open source file\n", -2)
# define ERROR_OPEN_DST error("asm: Could not create/open destination file\n", -3)
# define ERROR_EMPTY_FILE error("asm: Empty file\n", -4)

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

/*
** ===================
** loic
*/

typedef struct	s_op_conv
{
	char	*name;
	char	opcode_nb;
	void	(*fn)(char, char **); // n'hesite pas a modifier la signature'
	// ajoute les champs necessaire
}				t_op_conv;

/*
** ====================
*/

/* ============================== arguments.c =============================== */

int		parse_arguments(int argc, char **argv, t_flags *flags);

/* ================================ error.c ================================= */

int		error(char *str, int errno);

/* =============================== convert.c ================================ */

void	convert_file(char *src_path);

/* ================================ parse.c ================================= */

void	parse_line(char *line, int fd);

/* =============================== opcodes.c ================================ */

void name_fn(int fd, char **split);
void live_fn(int fd, char **split);

#endif
