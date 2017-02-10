/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:00:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/10 20:26:37 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	do_op(void (*op_fn)(t_proc *, t_op_arg[3]), t_proc *proc, t_op *op)
{
	t_op_arg	args[3];

	ft_bzero(args, sizeof(t_op_arg) * 3);
	get_argument_op(proc, op->value, args);
	op_fn(proc, args);
	proc->pc += (2 + args[0].size + args[1].size + args[2].size);
}

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
	ft_printf("[DEBUG] process_fork NOT IMPLEMENTED !!\n");
	// TODO
	// création d'un process enfant pour 'fork' et 'lfork'
	//if (parent)
	//	ft_memcpy(process, parent, sizeof(t_proc));
	return (new_process);
}

void	process_op(t_proc *proc, t_op *op)
{
	static void	(*opcode_fns[16])(t_proc *, t_op_arg[3]) =
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

	do_op(opcode_fns[op->value - 1], proc, op);
}
