/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:22:50 by akopera           #+#    #+#             */
/*   Updated: 2017/02/10 20:35:25 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld_op(t_proc *proc, t_op_arg args[3])
{
	t_registry	*reg;
	int			test;

	test = proc->pc - g_corewar.cycle_infos.arena;
	ft_printf("ld    ");
	ft_printf("\nTEST = %d\n", test);
	args[1].value = args[1].value % IDX_MOD;
	// récupération du registre r(arg2)
	if (args[1].value < REG_NUMBER)
	{
		reg = &proc->reg[args[1].value];
		// stocke arg1 dans reg
		swap_endianess((char *)reg, (char *)&args[0].value, sizeof(t_registry));
		proc->carry = 1;
	}
	// FIN de la fonction


	// Je comprends pas cette ligne:
	//test = (int*)proc->reg[arg_values[0] - 1];
	//(int*)proc->reg[arg_values[0] - 1] = arg_values[0];

	// pour DEBUG uniquement, swap de la valeur en mémoire
	// afin de récupérer quelque chose de lisible :)
	int	result;
	result = 0;	
	swap_endianess((char *)&result, (char *)reg, sizeof(int));
	ft_printf("[DEBUG] reg[%d] value : %d\n", args[1].value, result);
}
