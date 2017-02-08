/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:00:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/08 16:43:14 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_proc	*process_create(char *pc)
{
	static int	count = 0;

	count++;
	g_corewar.process_count = count;
	g_corewar.cycle_infos.running_proc = count;
	g_corewar.process = realloc(g_corewar.process, sizeof(t_proc) * count);
	g_corewar.process->pc = pc;
	return (g_corewar.process);
	// */
}

t_proc	*process_fork(t_proc *process, char *pc)
{
	t_proc	*new_process;

	(void)process;
	new_process = process_create(pc);
	// TODO
	// création d'un process enfant pour 'fork' et 'lfork'
	//if (parent)
	//	ft_memcpy(process, parent, sizeof(t_proc));
	return (new_process);
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
