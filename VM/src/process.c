/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:00:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/06 23:18:30 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_proc	*process_create(t_proc *parent, char *pc)
{
	t_proc	*process;

	process = (t_proc *)ft_memalloc(sizeof(t_proc));
	if (parent)
		ft_memcpy(process, parent, sizeof(t_proc));
	process->pc = pc;
	return (process);
}
