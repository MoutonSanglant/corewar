/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 18:00:16 by lalves            #+#    #+#             */
/*   Updated: 2017/01/25 20:21:17 by lalves           ###   ########.fr       */
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
	char	code;
	void	(*fn)(int, char *, char); // n'hesite pas a modifier la signature'
	// ajoute les champs necessaire
}				t_op_conv;

/*
** ====================
*/

/* ============================== arguments.c =============================== */

int		parse_arguments(int argc, char **argv, t_flags *flags);

/* ================================ error.c ================================= */

int		error(char *str, int errno);
void	memory_error(void);
void	name_error(void);
void	comment_error(void);

/* =============================== convert.c ================================ */

void	convert_file(char *src_path);

/* =============================== codage.c ================================ */

void	write_ocp(int fd, char *arg, int arg_nb);

/* ================================ parse.c ================================= */

void	parse_line(char *line, int fd);

/* =============================== opcodes.c ================================ */

void	name_fn(int fd, char *arg, char c);
void	comment_fn(int fd, char *arg, char c);
void	live_fn(int fd, char *arg, char c);
void	ld_fn(int fd, char *arg, char c);
void	st_fn(int fd, char *arg, char c);

/* =============================== write.c ================================ */

int		get_arg(char **arg, int *nb);
void	write_arg(int fd, int *nb, int byte_to_write);

#endif
