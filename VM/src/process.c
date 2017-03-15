/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:00:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/15 04:18:52 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	do_op(void (*op_fn)(t_proc *, t_op_arg[3]), t_proc *proc)
{
	t_op_arg	args[3];
	int			offset;
	//int			opcode;


	//ft_bzero(args, sizeof(t_op_arg) * 3);
	proc->ocp = 0;
	proc->wait = -1;
	g_corewar.reg_error = 0;
	
	
	offset = get_argument_op(proc, proc->op->value, args);
	//offset = get_argument_op(proc, opcode, args);
	if (op_fn == &zjmp_op)
	{
		op_fn(proc, args);
		return (0);
	}
	//opcode = (int)read_byte(proc->pc);

	/*
	//if (proc->id == 3 || proc->id == 6)
	if (g_corewar.cycle_infos.count > 3540 && g_corewar.cycle_infos.count < 3560)
	{
		if (proc->id == 5 || (proc->id >= 9 && proc->id <= 14))
		{
			t_op_arg	aa[3];

			ft_printf(" P%i @%i op: %x (::%x);\n", proc->id, proc->pc - g_corewar.cycle_infos.arena, opcode, proc->op->value);
			aa[0].value = 8;
			aff_op(proc, aa);
		}
	}
	*/
	//if (proc->offset != offset)
	//	return (offset);
	//if (opcode != proc->op->value)
	// TODO
	// Absolument pas sur du tout que ça soit ce qu'il faille faire...
	//if ((proc->ocp & 0b11111100) != (read_byte(proc->pc + 1) & 0b11111100))
	//if (proc->ocp != read_byte(proc->pc + 1))
	//	return (offset);
	op_fn(proc, args);
	//proc->op = NULL;
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


	int		opcode;
	opcode = (int)read_byte(proc->pc) - 1;
	proc->op = &g_op_tab[opcode];
	//proc->op = &g_op_tab[opcode];
	return (do_op(opcode_fns[opcode], proc));
	//return (do_op(opcode_fns[proc->op->value - 1], proc));
}
