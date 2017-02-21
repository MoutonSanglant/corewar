/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 07:40:04 by lalves            #+#    #+#             */
/*   Updated: 2017/02/21 09:34:33 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_ld(char *arg, t_label *u)
{
	if (!check_dir(arg, u) && !check_ind(arg, u))
		return (0);
	arg = next_arg(arg);
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}

int		check_st(char *arg, t_label *u)
{
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_ind(arg, u) && !check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}

int		check_add(char *arg, t_label *u)
{
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	if (u)
		u->pos = 0;
	return (1);
}

int		check_sub(char *arg, t_label *u)
{
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	if (u)
		u->pos = 0;
	return (1);
}

int		check_and(char *arg, t_label *u)
{
	if (!check_dir(arg, u) && !check_ind(arg, u) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_dir(arg, u) && !check_ind(arg, u) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}
