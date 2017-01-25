/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:33:29 by lalves            #+#    #+#             */
/*   Updated: 2017/01/25 20:56:40 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		get_arg_type(char *arg, int x)
{
	int i;

	i = 0;
	while (x > 1)
	{
		while (arg[i])
		{
			if (arg[i] == SEPARATOR_CHAR)
			{
				i += 2;
				break;
			}
			i++;
		}
		x--;
	}
	if (arg[i] == 'r')
		return (1);
	if (arg[i] == DIRECT_CHAR)
		return (2);
	return (3);
}

static void		third_arg(int fd, char *arg, char c)
{
	int arg_type;

	arg_type = get_arg_type(arg, 3);
	if (arg_type == 1) // reg
		c = c | 0b00000100;
	if (arg_type == 2) // dir
		c = c | 0b00001000;
	if (arg_type == 3) // ind
		c = c | 0b00001100;
	write(fd, &c, 1);
}

static void		second_arg(int fd, char *arg, char c, int arg_nb)
{
	int arg_type;

	arg_type = get_arg_type(arg, 2);
	if (arg_type == 1) // reg
		c = c | 0b00010000;
	if (arg_type == 2) // dir
		c = c | 0b00100000;
	if (arg_type == 3) // ind
		c = c | 0b00110000;
	if (arg_nb > 2)
		third_arg(fd, arg, c);
	else
		write(fd, &c, 1);
}

static void		first_arg(int fd, char *arg, char c, int arg_nb)
{
	int arg_type;

	arg_type = get_arg_type(arg, 1);
	if (arg_type == 1) // reg
		c = c | 0b01000000;
	if (arg_type == 2) // dir
		c = c | 0b10000000;
	if (arg_type == 3) // ind
		c = c | 0b11000000;
	if (arg_nb > 1)
		second_arg(fd, arg, c, arg_nb);
	else
		write(fd, &c, 1);
}

void			write_ocp(int fd, char *arg, int arg_nb)
{
	char c;

	c = 0;
	first_arg(fd, arg, c, arg_nb);
}
