/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:22:00 by akopera           #+#    #+#             */
/*   Updated: 2017/01/30 19:20:17 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live_op(t_player *player)
{
	if (!check_idle(player, 10))
			return ;
	player->next_op += DIR_SIZE + 1;
	ft_printf("live \n");
	player->idle = -1;
}
