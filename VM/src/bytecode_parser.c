/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:16:28 by akopera           #+#    #+#             */
/*   Updated: 2017/02/07 12:44:37 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	parse_bytecode(t_proc *proc)
{
	int			opcode;
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

	//if (!proc->next_op)
	//	proc->next_op = proc->bytecode;
	opcode = (int)proc->pc[0];
	if (opcode <= 16 && opcode > 0)
		opcode_fns[opcode - 1](proc);
}
