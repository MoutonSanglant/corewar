/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:25:31 by akopera           #+#    #+#             */
/*   Updated: 2017/01/30 19:20:02 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ldi_op(t_player *player)
{
	if (!check_idle(player, 25))
			return ;
	ft_printf("ldi   ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);
	player->idle = -1;
}
