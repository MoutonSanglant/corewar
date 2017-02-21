/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 18:00:16 by lalves            #+#    #+#             */
/*   Updated: 2017/02/21 17:05:20 by lalves           ###   ########.fr       */
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

typedef struct	s_op_check
{
	char	*name;
	int		(*fn)(char *, t_env *);
}				t_op_check;

int				error(char *str, int errno);
int				name_error(void);
int				comment_error(void);

void			convert_file(char *src_path);
t_label			*init_label(char *line, size_t i);
t_env			*init_env(char *src_path);
void			clear_env(t_env **env);
char			*convert_path(char *path);

void			write_ocp(int fd, char *arg, int arg_nb);

void			parse_line(char *line, t_env *env);
void			clean_split_line(char ***tab, char **line);

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
char			**get_op_tab(int i);
void			check_cmd_length(int fd);
char			*save_label(char *line, t_env *env);
int				check_opcode(char *line, t_env *env);
int				check_args(char *line, t_env *env);

char			**split_line(char *str);
int				before_space(char *str, int i);
int				after_space(char *str, int i);

char			*next_arg(char *arg);
int				check_reg(char *arg);
int				check_ind(char *arg, t_env *env);
int				check_dir(char *arg, t_env *env);
int				check_live(char *arg, t_env *env);

int				check_ld(char *arg, t_env *env);
int				check_st(char *arg, t_env *env);
int				check_add(char *arg, t_env *env);
int				check_sub(char *arg, t_env *env);
int				check_and(char *arg, t_env *env);

int				check_or(char *arg, t_env *env);
int				check_xor(char *arg, t_env *env);
int				check_zjmp(char *arg, t_env *env);
int				check_ldi(char *arg, t_env *env);
int				check_sti(char *arg, t_env *env);

int				check_fork(char *arg, t_env *env);
int				check_lld(char *arg, t_env *env);
int				check_lldi(char *arg, t_env *env);
int				check_lfork(char *arg, t_env *env);
int				check_aff(char *arg, t_env *env);

void			check_label_fill(t_env *env);

#endif
