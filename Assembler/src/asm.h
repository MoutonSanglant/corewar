/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 18:00:16 by lalves            #+#    #+#             */
/*   Updated: 2016/10/12 22:17:19 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

#define ASM_H

# include <op.h>
# include <libft.h>
# include <libftprintf.h>

#define USAGE error("Usage: ./asm [-a] mon_champion.s\n", -1)
#define ERROR_OPEN_SRC error("asm: Could not open source file\n", -2)
#define ERROR_OPEN_DST error("asm: Could not create/open destination file\n", -3)
#define ERROR_EMPTY_FILE error("asm: Empty file\n", -4)


typedef struct	s_op_conv
{
	char	*name;
	void	(*fn)(int, char **);
}				t_op_conv;

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
