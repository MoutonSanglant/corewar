/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:22:50 by akopera           #+#    #+#             */
/*   Updated: 2017/02/08 21:48:04 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld_op(t_proc *proc)
{
	t_registry	*reg;
	int			arg_s[2];
	int			args[2];
	int			offset;
	int			i;
	int			test;

	test = proc->pc - g_corewar.cycle_infos.arena;
	ft_printf("ld    ");
	ft_printf("\nTEST = %d\n", test);
	get_argument_sizes(*(proc->pc + 1), (int)proc->pc[0], arg_s);
	i = 0;
	offset = 2;
	// conversion de tous les arguments
	while (i < 2)
	{
		swap_endianess((char *)&args[i], (char *)&proc->pc[offset], arg_s[i]);
		offset += arg_s[i];
		i++;
	}
	args[1] = args[1] % IDX_MOD;
	// récupération du registre r(arg2)
	if (args[1] < REG_NUMBER)
	{
		reg = &proc->reg[args[1]];
		// stocke arg1 dans reg
		swap_endianess((char *)reg, (char *)&args[0], sizeof(t_registry));
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
	ft_printf("[DEBUG] reg[%d] value : %d\n", args[1], result);
}
