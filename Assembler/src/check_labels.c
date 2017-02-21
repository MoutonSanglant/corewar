/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:42:16 by lalves            #+#    #+#             */
/*   Updated: 2017/02/21 16:23:05 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	find_name(char *name, t_label *declare)
{
	t_label *lst;

	lst = declare;
	while (lst)
	{
		if (!ft_strcmp(name, lst->label))
			return (1);
		lst = lst->next;
	}
	ft_printf("name = %s\n", name);
	return (0);
}

void		check_label_fill(t_env *env)
{
	t_label *lst;

	lst = env->use;
	while (lst)
	{
		if (!find_name(lst->label, env->declare))
			exit(ERROR_SYNTAX);
		lst = lst->next;
	}
}
