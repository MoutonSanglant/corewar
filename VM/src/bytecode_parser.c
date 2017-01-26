/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:16:28 by akopera           #+#    #+#             */
/*   Updated: 2017/01/26 18:02:09 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//typedef void (*t_op_fn)(void *, void *, void *);

typedef struct s_opcode_fn
{
	t_ops	opcode;
	void	(*fn)(void);
}				t_opcode_fn;

void *g_opcode_fns[16] =
{
	{ &live_op},
	{ &ld_op },
	{ &st_op },
	{ &add_op },
	{ OP_SUB, &sub_op },
	{ OP_AND, &and_op },
	{ OP_OR, &or_op },
	{ OP_XOR, &xor_op },
	{ OP_ZJMP, &zjmp_op},
	{ OP_LDI, &ldi_op},
	{ OP_STI, &sti_op},
	{ OP_FORK, &fork_op},
	{ OP_LLD, &lld_op },
	{ OP_LDI, &lldi_op },
	{ OP_LFORK, &lfork_op },
	{ OP_AFF, &aff_op }
};

void	parse_bytecode(char *bytecode)
{
	int opcode;

	if (opcode < 16 && opcode > 0)
		g_opcode_fns[opcode - 1].fn();
}
