/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_functions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:58:03 by akopera           #+#    #+#             */
/*   Updated: 2017/01/27 19:17:33 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live_op(t_player *player)
{
	player->next_op += DIR_SIZE + 1;
	ft_printf("live \n");
}

void	ld_op(t_player *player)
{
	ft_printf("ld    ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);
}
void	st_op(t_player *player)
{
	ft_printf("st    ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	add_op(t_player *player)
{
	ft_printf("add   ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	sub_op(t_player *player)
{
	ft_printf("sub   ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	and_op(t_player *player)
{
	ft_printf("and   ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	or_op(t_player *player)
{
	ft_printf("or    ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	xor_op(t_player *player)
{
	ft_printf("xor   ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	zjmp_op(t_player *player)
{
	player->next_op += IND_SIZE + 1;
	ft_printf("zjmp  \n");

}
void	ldi_op(t_player *player)
{
	ft_printf("ldi   ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	sti_op(t_player *player)
{
	ft_printf("sti   ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	fork_op(t_player *player)
{
	player->next_op += IND_SIZE + 1;
	ft_printf("fork  \n");

}
void	lld_op(t_player *player)
{
	ft_printf("lld   ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	lldi_op(t_player *player)
{
	ft_printf("lldi  ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	lfork_op(t_player *player)
{
	player->next_op += IND_SIZE + 1;
	ft_printf("lfork \n");

}
void	aff_op(t_player *player)
{
	ft_printf("aff   ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);

}
void	unknown_op(t_player *player)
{
	(void)player;
	player->next_op += 1;
	ft_printf("no op \n");
}
