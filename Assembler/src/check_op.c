/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 07:38:59 by lalves            #+#    #+#             */
/*   Updated: 2017/02/21 09:28:32 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_label(char *arg, t_label *u)
{
	size_t	i;
	t_label	*new;

	i = 0;
	if (arg[i] != LABEL_CHAR)
		return (0);
	i++;
	while (arg[i] && arg[i] != SEPARATOR_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, arg[i]))
			return (0);
		i++;
	}
	new = init_label(&(arg[1]), i);
	new->next = u;
	u = new;
	return (1);
}

int				check_reg(char *arg)
{
	int i;

	i = 0;
	if (arg[i] != 'r')
		return (0);
	i++;
	while (arg[i] && arg[i] != SEPARATOR_CHAR)
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int				check_ind(char *arg, t_label *u)
{
	int i;

	i = 0;
	if (check_label(arg, u))
		return (1);
	if (arg[i] == '-')
		i++;
	while (arg[i] && arg[i] != SEPARATOR_CHAR)
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int				check_dir(char *arg, t_label *u)
{
	int i;

	i = 0;
	if (arg[i] != DIRECT_CHAR)
		return (0);
	i++;
	if (check_label(&arg[i], u))
		return (1);
	if (arg[i] == '-')
		i++;
	while (arg[i] && arg[i] != SEPARATOR_CHAR)
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int				check_live(char *arg, t_label *u)
{
	if (!check_dir(arg, u))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}
