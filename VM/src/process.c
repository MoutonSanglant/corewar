/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:00:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/14 00:32:14 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	do_op(void (*op_fn)(t_proc *, t_op_arg[3]), t_proc *proc)
{
	t_op_arg	args[3];
	int			offset;
	int			opcode;

	ft_bzero(args, sizeof(t_op_arg) * 3);
	offset = get_argument_op(proc, proc->op->value, args);
	g_corewar.reg_error = 0;
	if (op_fn == &zjmp_op)
	{
		op_fn(proc, args);
		return (0);
	}
	opcode = (int)read_byte(proc->pc);
	if (opcode != proc->op->value)
		return (offset);

	/*
	t_op_arg	aa[3];

	if (proc->id == 3 || proc->id == 6)
	{
		ft_printf("HELLO %i (@%i) !                 ", proc->id, proc->pc - g_corewar.cycle_infos.arena);
		aa[0].value = 3;
		aff_op(proc, aa);
	}
	*/
	op_fn(proc, args);
	return (offset);
}

char		*process_move(t_proc *proc, int offset)
{
	char	*pc;
	char	*mem;
	int		overflow;

	proc->op = NULL;
	pc = proc->pc + offset;
	if ((mem = g_corewar.cycle_infos.arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	if (pc >= mem + MEM_SIZE)
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
	if (proc)
	{
		ft_memcpy(new_proc, &buf, sizeof(t_proc));
		process_move(new_proc, offset);
		new_proc->op = NULL;
		//new_proc->live = 0;
	}
	new_proc->id = uid++;
	new_proc->wait = -1;
	return (new_proc);
}

int			process_op(t_proc *proc)
{
	static void	(*opcode_fns[OP_COUNT])(t_proc *, t_op_arg[3]) = {
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
