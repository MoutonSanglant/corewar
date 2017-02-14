/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:22:50 by akopera           #+#    #+#             */
/*   Updated: 2017/02/14 12:55:07 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld_op(t_proc *proc, t_op_arg args[3])
{
	//t_registry	*reg;
	int			test;

	test = proc->pc - g_corewar.cycle_infos.arena;
	ft_printf("ld    ");
	ft_printf("\nTEST = %d\n", test);
	args[1].value = args[1].value % IDX_MOD;
	if (args[1].value - 1 < 0)
		return ;
	// récupération du registre r(arg2)
	if (args[1].value < REG_NUMBER)
	{
		//reg = &proc->reg[args[1].value - 1];
		// stocke arg1 dans reg
		if (args[0].type == T_DIR)
			store_register(proc->reg, args[1].value, (char *)&args[0].value);
			//swap_endianess((char *)reg, (char *)&args[0].value, sizeof(t_registry));
		if (args[0].type == T_IND)
			store_register(proc->reg, args[1].value, proc->pc + (args[0].value % IDX_MOD));
			//swap_endianess((char *)reg, proc->pc + (args[0].value % IDX_MOD), sizeof(t_registry));
		proc->carry = 1;
		int	result;
		result = read_register(proc->reg, args[1].value);
		ft_printf("[DEBUG] reg[%d] value : %d\n", args[1].value, result);
	}
	// FIN de la fonction


	// Je comprends pas cette ligne:
	//test = (int*)proc->reg[arg_values[0] - 1];
	//(int*)proc->reg[arg_values[0] - 1] = arg_values[0];

	// pour DEBUG uniquement, swap de la valeur en mémoire
	// afin de récupérer quelque chose de lisible :)
	//swap_endianess((char *)&result, (char *)reg, sizeof(int));
}
