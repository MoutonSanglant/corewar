/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:24:31 by akopera           #+#    #+#             */
/*   Updated: 2017/01/29 18:51:41 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	or_op(t_player *player)
{
	ft_printf("or    ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);
}
