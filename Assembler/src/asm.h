/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 18:00:16 by lalves            #+#    #+#             */
/*   Updated: 2017/02/21 09:48:26 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

# define ASM_H

# include <op.h>
# include <libft.h>
# include <libftprintf.h>

# define USAGE error("Usage: ./asm [-a] mon_champion.s\n", -1)
# define ERROR_OPEN_SRC error("asm: Could not open source file\n", -2)
# define ERROR_READ_SRC error("asm: Could not read source file\n", -3)
# define ERROR_SYNTAX error("asm: Syntax error\n", -4)
# define ERROR_OPEN_DST error("asm: Could not create/open dest file\n", -5)
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

typedef struct	s_op_conv
{
	char	*name;
	char	code;
	int		(*fn)(int, char *, char);
}				t_op_conv;

typedef struct	s_label
{
	char			*label;
	off_t			pos;
	struct s_label	*next;
}				t_label;

typedef struct	s_op_check
{
	char	*name;
	int		(*fn)(char *, t_label *);
}				t_op_check;

typedef struct	s_env
{
	t_label	*declare;
	t_label	*use;
	int		src_fd;
	int		dst_fd;
	int		name;
	int		comment;
	int		opcode;
}				t_env;

int				parse_arguments(int argc, char **argv, t_flags *flags);

int				error(char *str, int errno);
int				name_error(void);
int				comment_error(void);

void			convert_file(char *src_path);
t_label			*init_label(char *line, size_t i);

void			write_ocp(int fd, char *arg, int arg_nb);

void			parse_line(char *line, int fd);

int				name_fn(int fd, char *arg);
int				comment_fn(int fd, char *arg);
int				live_fn(int fd, char *arg, char c);
int				ld_fn(int fd, char *arg, char c);
int				st_fn(int fd, char *arg, char c);

int				add_fn(int fd, char *arg, char c);
int				sub_fn(int fd, char *arg, char c);
int				and_fn(int fd, char *arg, char c);
int				or_fn(int fd, char *arg, char c);
int				xor_fn(int fd, char *arg, char c);

int				zjmp_fn(int fd, char *arg, char c);
int				ldi_fn(int fd, char *arg, char c);
int				sti_fn(int fd, char *arg, char c);
int				fork_fn(int fd, char *arg, char c);
int				lld_fn(int fd, char *arg, char c);

int				lldi_fn(int fd, char *arg, char c);
int				lfork_fn(int fd, char *arg, char c);
int				aff_fn(int fd, char *arg, char c);

int				get_arg(char **arg, int *nb);
void			write_arg(int fd, int *nb, int byte_to_write);
void			write_prog_size(int fd);

int				check_invalid_file(t_env *env);
int				type_of_line(char *line);
void			check_cmd_length(int fd);
char			*save_label(char *line, t_env *env);
int				check_opcode(char *line, t_env *env);
int				check_args(char *line, t_label *u);

char			**split_line(char *str);
int				before_space(char *str, int i);
int				after_space(char *str, int i);

char			*next_arg(char *arg);
int				check_reg(char *arg);
int				check_ind(char *arg, t_label *u);
int				check_dir(char *arg, t_label *u);
int				check_live(char *arg, t_label *u);

int				check_ld(char *arg, t_label *u);
int				check_st(char *arg, t_label *u);
int				check_add(char *arg, t_label *u);
int				check_sub(char *arg, t_label *u);
int				check_and(char *arg, t_label *u);

int				check_or(char *arg, t_label *u);
int				check_xor(char *arg, t_label *u);
int				check_zjmp(char *arg, t_label *u);
int				check_ldi(char *arg, t_label *u);
int				check_sti(char *arg, t_label *u);

int				check_fork(char *arg, t_label *u);
int				check_lld(char *arg, t_label *u);
int				check_lldi(char *arg, t_label *u);
int				check_lfork(char *arg, t_label *u);
int				check_aff(char *arg, t_label *u);

#endif
