/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknown_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:58:03 by akopera           #+#    #+#             */
/*   Updated: 2017/01/30 19:11:11 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	unknown_op(t_player *player)
{
//	if (!check_idle(player, 5))
//			return ;
	player->next_op += 1;
	ft_printf("no op \n");
}
