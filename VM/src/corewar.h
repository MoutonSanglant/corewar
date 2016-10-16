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
[[-n number] champion1.cor] ..."
#define ERROR_OPEN error("corewar: Could not open file", -2)
#define ERROR_EMPTY_FILE error("corewar: Empty file", -3)
#define ERROR_INVALID_FILETYPE error("corewar: Incorrect file type", -4)

/* ================================ error.c ================================= */
int		error(char *str, int errno);

/* ================================= read.c ================================= */
void	read_binary(char *path);

/* ================================ bytes.c ================================= */
int		bytes_to_int(char *b);

#endif
