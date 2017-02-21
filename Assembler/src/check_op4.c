/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 07:39:46 by lalves            #+#    #+#             */
/*   Updated: 2017/02/21 09:34:52 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_fork(char *arg, t_label *u)
{
	if (!check_dir(arg, u))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}

int		check_lld(char *arg, t_label *u)
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

int		check_lldi(char *arg, t_label *u)
{
	if (!check_dir(arg, u) && !check_ind(arg, u) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_dir(arg, u) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}

int		check_lfork(char *arg, t_label *u)
{
	if (!check_dir(arg, u))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}

int		check_aff(char *arg, t_label *u)
{
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	if (u)
		u->pos = 0;
	return (1);
}
