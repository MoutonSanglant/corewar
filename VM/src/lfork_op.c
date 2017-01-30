/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:27:40 by akopera           #+#    #+#             */
/*   Updated: 2017/01/30 19:20:11 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lfork_op(t_player *player)
{
	if (!check_idle(player, 1000))
			return ;
	player->next_op += IND_SIZE + 1;
	ft_printf("lfork \n");
	player->idle = -1;
}
