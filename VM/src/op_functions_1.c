/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_functions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:58:03 by akopera           #+#    #+#             */
/*   Updated: 2017/01/27 18:53:50 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live_op(t_player *player)
{
	(void)player;
	//ft_printf("live\n");
}

void	ld_op(t_player *player)
{
	ft_printf("ld\n");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);
}
void	st_op(t_player *player)
{
	ft_printf("st\n");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	add_op(t_player *player)
{
	ft_printf("add\n");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	sub_op(t_player *player)
{
	ft_printf("sub\n");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	and_op(t_player *player)
{
	ft_printf("and\n");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	or_op(t_player *player)
{
	ft_printf("or\n");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	xor_op(t_player *player)
{
	ft_printf("xor\n");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	zjmp_op(t_player *player)
{
	(void)player;
	ft_printf("zjmp\n");

}
void	ldi_op(t_player *player)
{
	ft_printf("ldi\n");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	sti_op(t_player *player)
{
	ft_printf("sti\n");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	fork_op(t_player *player)
{
	(void)player;
	ft_printf("fork\n");

}
void	lld_op(t_player *player)
{
	ft_printf("lld\n");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	lldi_op(t_player *player)
{
	ft_printf("lldi\n");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	lfork_op(t_player *player)
{
	(void)player;
	ft_printf("lfork\n");

}
void	aff_op(t_player *player)
{
	ft_printf("aff\n");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	unknown_op(t_player *player)
{
	(void)player;
	ft_printf("unkown op\n");
}
