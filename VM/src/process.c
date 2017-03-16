/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:00:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/16 11:43:55 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	do_op(void (*op_fn)(t_proc *, t_op_arg[3]), t_proc *proc)
{
	t_op_arg	args[3];
	int			offset;

	proc->wait = -1;
	g_corewar.reg_error = 0;

	offset = get_argument_op(proc, proc->start_op->value, args);

	/*
	if (g_corewar.cycle_infos.count > 800)
	{
		ft_printf("proc.ocp: %x\nbyte ocp: %x\n", proc->ocp, read_byte(proc->pc + 1));
	}
	*/
	if (op_fn == &zjmp_op)
	{
		// zjmp n'est pas concerné
		op_fn(proc, args);
		return (0);
	}

	if (!proc->start_op->ocp || proc->ocp == read_byte(proc->pc + 1)) // CONFIRME
		op_fn(proc, args);
		// C'est ici que tout se joue, quand l'OCP a été corrompu, l'opération
		// n'est pas exécutée et il faut avancer en fonction du nouvel OCP
	return (offset);
}

char		*process_move(t_proc *proc, int offset)
{
	char	*pc;
	char	*mem;

	proc->wait = -1;
	//proc->op = NULL;
	proc->ocp = 0;
	// get_addr
	pc = proc->pc + offset;
	if ((mem = g_corewar.cycle_infos.arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	else if (pc > mem + MEM_SIZE)
		pc = mem + (pc - (mem + MEM_SIZE)) % MEM_SIZE;
	proc->pc = pc;
	return (pc);
}

t_proc		*process_create(char *pc, t_proc *parent)
{
	static unsigned int	uid = 0;
	t_proc				*new_proc;
	t_proc				buf;
	int					count;

	if (parent)
		ft_memcpy(&buf, parent, sizeof(t_proc));
	g_corewar.process_count++;
	count = g_corewar.process_count;
	g_corewar.process = realloc(g_corewar.process, sizeof(t_proc) * count);
	if (!g_corewar.process)
		error(ERRNO_MEMORY, "process create");
	new_proc = &g_corewar.process[count - 1];
	ft_bzero(new_proc, sizeof(t_proc));
	new_proc->pc = pc;
	if (parent)
		ft_memcpy(new_proc, &buf, sizeof(t_proc));
	new_proc->id = uid++;
	new_proc->wait = -1;
	//new_proc->op = NULL;
	new_proc->ocp = 0;
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

	//int		opcode;
	//opcode = (int)read_byte(proc->pc) - 1;


	//int		opcode;
	//opcode = (int)read_byte(proc->pc) - 1;
	//proc->end_op = &g_op_tab[opcode];
	//proc->op = &g_op_tab[opcode];
	return (do_op(opcode_fns[proc->start_op->value - 1], proc));
	//return (do_op(opcode_fns[proc->op->value - 1], proc));
}
