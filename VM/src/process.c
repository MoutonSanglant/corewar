/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:00:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/14 20:56:32 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	do_op(void (*op_fn)(t_proc *, t_op_arg[3]), t_proc *proc, t_op *op)
{
	t_op_arg	args[3];
	int			offset;

	ft_bzero(args, sizeof(t_op_arg) * 3);
	offset = get_argument_op(proc, op->value, args);
	op_fn(proc, args);
	return (offset);
}

char		*process_move(t_proc *proc, int offset)
{
	char	*arena;

	arena = g_corewar.cycle_infos.arena;
	//proc->pc = proc->pc + offset;
	if (proc->pc + offset >= (arena + MEM_SIZE))
		proc->pc = (arena + ((proc->pc - arena) % MEM_SIZE));
	else
		proc->pc = proc->pc + offset;
	return (proc->pc);
}

void	process_kill(t_proc *proc, int idx)
{
	t_proc	*right;
	int		size;

	g_corewar.process_count--;
	size = g_corewar.process_count - idx;
	if (size <= 0)
		return ;
	//ft_printf("size is %i\n", size);
	right = malloc(sizeof(t_proc) * size);
	ft_memcpy(right, &proc[idx + 1], sizeof(t_proc) * size);
	g_corewar.process = realloc(g_corewar.process, sizeof(t_proc) * g_corewar.process_count);
	if (!g_corewar.process)
		error(ERRNO_MEMORY, "process kill");
	// TODO: ça segfault
	ft_memcpy(&g_corewar.process[idx], right, sizeof(t_proc) * size);
	free(right);
}

t_proc	*process_create(char *pc)
{
	int		count;

	g_corewar.process_count++;
	count = g_corewar.process_count;
	g_corewar.process = realloc(g_corewar.process, sizeof(t_proc) * count);
	if (!g_corewar.process)
		error(ERRNO_MEMORY, "process create");
	ft_bzero(&g_corewar.process[count - 1], sizeof(t_proc));
	g_corewar.process[count - 1].pc = pc;
	return (&g_corewar.process[count - 1]);
}

void	process_fork(t_proc *proc, int offset)
{
	t_proc	*new_proc;
	t_proc	buf;

	ft_memcpy(&buf, proc, sizeof(t_proc));
	new_proc = process_create(proc->pc);
	ft_memcpy(new_proc, &buf, sizeof(t_proc));
	process_move(new_proc, offset);
}

int		process_op(t_proc *proc, t_op *op)
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

	return (do_op(opcode_fns[op->value - 1], proc, op));
}
