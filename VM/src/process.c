/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:00:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/15 19:33:59 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	do_op(void (*op_fn)(t_proc *, t_op_arg[3]), t_proc *proc)
{
	t_op_arg	args[3];
	int			offset;

	proc->ocp = 0;
	//ft_bzero(args, sizeof(t_op_arg) * 3);
	proc->wait = -1;
	g_corewar.reg_error = 0;
	
	int opcode = proc->end_op->value - 1;
	if (!(opcode < OP_COUNT && opcode >= 0))
	{
		// TODO TODO TODO
		// Il y a quelque chose à faire par là ...
		// Important: si l'op final a changée, on ne peut plus appeler
		// get_argument_op puisque l'index de l'opcode ne correspond
		// à rien...
		// Comment gérer un opcode > OP_COUNT ? 
		// faut il lire l'octet de codage et avancer en fonction ?
		// Je ne sais pas, il faut faire des tests...
		offset = get_argument_op(proc, proc->start_op->value, args);
		//return (1);
		return (2);
	}
	offset = get_argument_op(proc, proc->end_op->value, args);
	//offset = get_argument_op(proc, opcode, args);


	/*	
	//if (proc->id == 3 || proc->id == 6)
	if (g_corewar.cycle_infos.count == 2235)
	{
//		if (proc->id == 5 || (proc->id >= 9 && proc->id <= 14))
//		{
			t_op_arg	aa[3];

			ft_printf(" P%i @%i op: %x (::%x->%x);\n", proc->id, proc->pc - g_corewar.cycle_infos.arena, opcode, proc->start_op->value, proc->end_op->value);
			aa[0].value = 8;
			aff_op(proc, aa);
//		}
	}
	*/
	
	//if (proc->offset != offset)
	//	return (offset);
	// TODO
	// Absolument pas sur du tout que ça soit ce qu'il faille faire...
	//if ((proc->ocp & 0b11111100) != (read_byte(proc->pc + 1) & 0b11111100))
	//int ocp;
	//ocp = proc->ocp;
	//if (ocp != read_byte(proc->pc + 1))
	/*
	int			opcode;
	opcode = proc->op->value;
	if (opcode != read_byte(proc->pc) - 1)
	*/
	//	return (offset);
	//
	//	TODO TODO TODO
	// Par ici aussi...
	if (proc->start_op->value != proc->end_op->value)
		// C'est ici que tout se joue, quand l'op n'est plus bon, il faut
		// avancer en fonction de l'ocp, mais la valeur change en fonction
		// de quelque chose ? (l'opcode peut être ?)
		//
		// Visiblement, ce n'est pas l'opcode, ça peut etre l'octet de codage,
		// ou... les paramètres ? (registre invalide)
		return (3);
	if (op_fn == &zjmp_op)
	{
		op_fn(proc, args);
		return (0);
	}
		//return (offset);
	op_fn(proc, args);
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
	proc->end_op = &g_op_tab[opcode];
	//proc->op = &g_op_tab[opcode];
	return (do_op(opcode_fns[opcode], proc));
	//return (do_op(opcode_fns[proc->op->value - 1], proc));
}
