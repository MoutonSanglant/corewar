/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:00:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/12 14:01:18 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	do_op(void (*op_fn)(t_proc *, t_op_arg[3]), t_proc *proc)
{
	t_op_arg	args[3];
	int			offset;

	ft_bzero(args, sizeof(t_op_arg) * 3);
	offset = get_argument_op(proc, proc->op->value, args);
	g_corewar.reg_error = 0;
	op_fn(proc, args);
	if (op_fn == &zjmp_op)
		return (0);
	return (offset);
}

char		*process_move(t_proc *proc, int offset)
{
	char	*pc;
	char	*mem;
	int		overflow;

	pc = proc->pc + offset;

	proc->op = NULL;
	if ((mem = g_corewar.cycle_infos.arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	if (pc > mem + MEM_SIZE)
	{
		overflow = (pc - (mem + MEM_SIZE)) % MEM_SIZE;
		pc = mem + overflow;
	}
	proc->pc = pc;
	return (pc);
}

t_proc		*process_create(char *pc, t_proc *proc, int offset)
{
	static unsigned int	uid = 0;
	t_proc				*new_proc;
	t_proc				buf;
	int					count;

	if (proc)
		ft_memcpy(&buf, proc, sizeof(t_proc));
	g_corewar.process_count++;
	count = g_corewar.process_count;
	g_corewar.process = realloc(g_corewar.process, sizeof(t_proc) * count);
	if (!g_corewar.process)
		error(ERRNO_MEMORY, "process create");
	new_proc = &g_corewar.process[count - 1];
	ft_bzero(new_proc, sizeof(t_proc));
	new_proc->pc = pc;
	new_proc->id = uid++;
	new_proc->wait = -1;
	if (proc)
	{
		ft_memcpy(new_proc, &buf, sizeof(t_proc));
		process_move(new_proc, offset);
	}
	return (new_proc);
}

int			process_op(t_proc *proc)
{
	static void	(*opcode_fns[16])(t_proc *, t_op_arg[3]) = {
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

	return (do_op(opcode_fns[proc->op->value - 1], proc));
}
