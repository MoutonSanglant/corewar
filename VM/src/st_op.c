/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:18 by akopera           #+#    #+#             */
/*   Updated: 2017/01/29 18:51:48 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st_op(t_player *player)
{
	ft_printf("st    ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);
}
