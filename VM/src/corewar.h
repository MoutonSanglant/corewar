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

# define USAGE "Usage: ./corewar [-dump nbr_cycles] \
[[-n number] champion1.cor] ...\n"
#define ERROR_OPEN error("corewar: Could not open file\n", -2)
#define ERROR_EMPTY_FILE error("corewar: Empty file\n", -3)
#define ERROR_INVALID_FILETYPE error("corewar: Incorrect file type\n", -4)

typedef char t_registry[REG_SIZE];

typedef struct	s_proc
{
	t_registry[REG_NUMBER]	reg;
	void					*pc;
	int						carry; // 0 ou 1
}				t_proc;

typedef struct	s_player
{
	int		number;
}				t_player;

/* ================================ error.c ================================= */
int		error(char *str, int errno);

/* ================================= read.c ================================= */
void	read_binary(char *path);

/* ================================ bytes.c ================================= */
int		bytes_to_int(char *b);

#endif
