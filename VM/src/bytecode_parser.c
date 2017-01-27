/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:16:28 by akopera           #+#    #+#             */
/*   Updated: 2017/01/27 18:31:29 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//typedef void (*t_op_fn)(void *, void *, void *);

typedef struct s_opcode_fn
{
	t_ops	opcode;
	void	(*fn)(void);
}				t_opcode_fn;

void (*opcode_fns[16])(t_player *player) =
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
void	parse_bytecode(t_player *player)
{
	int opcode;

	opcode = (int)player->next_op[0];
	if (opcode < 16 && opcode > 0)
		opcode_fns[opcode - 1](player);
}
