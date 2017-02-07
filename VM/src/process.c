/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:00:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/07 14:36:17 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_proc	*process_create(t_proc *parent, char *pc)
{
	static int	count = 0;
	//t_proc		*process;
	t_proc		*tmp;

	count++;
	g_corewar.process_count = count;
	// (re)alloc 'count' process
	if (g_corewar.process)
	{
		tmp = g_corewar.process;
		g_corewar.process = ft_memalloc(sizeof(t_proc) * count);
		// TODO
		// Comme l'adresse du process change, les autres champions
		// n'ont plus accès à leur process, c'est mauvais. :)
		ft_memcpy(g_corewar.process, tmp, sizeof(t_proc) * (count - 1));
		free(tmp);
	}
	else
		g_corewar.process = ft_memalloc(sizeof(t_proc));
	// TODO
	// création d'un process enfant pour 'fork' et 'lfork'
	(void)parent;
	//if (parent)
	//	ft_memcpy(process, parent, sizeof(t_proc));
	g_corewar.process->pc = pc;
	return (g_corewar.process);
}

void	process_op(t_proc *proc, t_op *op)
{
	static void	(*opcode_fns[16])(t_proc *proc) =
	{
		&live_op,
		&ld_op,
		&st_op,
		&add_op,
		&sub_op,
		&and_op,
		&or_op,
		&xor_op,
		&zjmp_op,
		&ldi_op,
		&sti_op,
		&fork_op,
		&lld_op,
		&lldi_op,
		&lfork_op,
		&aff_op
	};

	opcode_fns[op->value - 1](proc);
}

void	process_move(t_proc *proc, t_op *op)
{
	int	arg_sizes[3];
	
	//if (op->ocp)
	//	ft_printf("ocp: %i\n", op->ocp);
	
	get_argument_sizes(*(proc->pc + 1), op->value, arg_sizes);
	proc->pc += (2 + arg_sizes[0] + arg_sizes[1] + arg_sizes[2]);
}
