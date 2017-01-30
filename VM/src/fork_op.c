/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:26:17 by akopera           #+#    #+#             */
/*   Updated: 2017/01/30 19:58:55 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	fork_op(t_player *player)
{
	if (!check_idle(player, 800))
			return ;
	player->next_op += IND_SIZE + 1;
	ft_printf("fork  \n");
	player->idle = -1;
}
