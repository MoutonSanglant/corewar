/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:28:13 by akopera           #+#    #+#             */
/*   Updated: 2017/01/29 18:29:56 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff_op(t_player *player)
{
	ft_printf("aff   ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);
}
