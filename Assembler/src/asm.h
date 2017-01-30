/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 18:00:16 by lalves            #+#    #+#             */
/*   Updated: 2017/01/30 20:32:44 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

#define ASM_H

# include <op.h>
# include <libft.h>
# include <libftprintf.h>

# define USAGE error("Usage: ./asm [-a] mon_champion.s\n", -1)
# define ERROR_OPEN_SRC error("asm: Could not open source file\n", -2)
# define ERROR_READ_SRC error("asm: Could not read source file\n", -3)
# define ERROR_SYNTAX error("asm: Syntax error\n", -4)
# define ERROR_OPEN_DST error("asm: Could not create/open destination file\n", -5)
# define ERROR_EMPTY_FILE error("asm: Empty file\n", -6)
# define ERROR_MALLOC error("asm: Could not allocate memory with malloc\n", -7)

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
	void	(*fn)(int, char *, char);
}				t_op_conv;

/* ============================== arguments.c =============================== */

int		parse_arguments(int argc, char **argv, t_flags *flags);

/* ================================ error.c ================================= */

int		error(char *str, int errno);
int		name_error(void);
int		comment_error(void);

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

/* =============================== opcodes2.c ================================ */

void	add_fn(int fd, char *arg, char c);
void	sub_fn(int fd, char *arg, char c);
void	and_fn(int fd, char *arg, char c);
void	or_fn(int fd, char *arg, char c);
void	xor_fn(int fd, char *arg, char c);

/* =============================== opcodes3.c ================================ */

void	zjmp_fn(int fd, char *arg, char c);
void	ldi_fn(int fd, char *arg, char c);
void	sti_fn(int fd, char *arg, char c);
void	fork_fn(int fd, char *arg, char c);
void	lld_fn(int fd, char *arg, char c);

/* =============================== opcodes4.c ================================ */

void	lldi_fn(int fd, char *arg, char c);
void	lfork_fn(int fd, char *arg, char c);
void	aff_fn(int fd, char *arg, char c);

/* =============================== write.c ================================ */

int		get_arg(char **arg, int *nb);
void	write_arg(int fd, int *nb, int byte_to_write);
void	write_prog_size(int fd);

/* =============================== check_name.c ================================ */

void	check_name(int fd);

/* =============================== check_comment.c ================================ */

void	check_comment(int fd);

#endif
