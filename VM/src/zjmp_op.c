/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:25:05 by akopera           #+#    #+#             */
/*   Updated: 2017/01/30 19:21:06 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp_op(t_player *player)
{
	if (!check_idle(player, 20))
			return ;
	player->next_op += IND_SIZE + 1;
	ft_printf("zjmp  \n");
	player->idle = -1;
}
