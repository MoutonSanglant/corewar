/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:25:47 by akopera           #+#    #+#             */
/*   Updated: 2017/01/29 18:25:52 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti_op(t_player *player)
{
	ft_printf("sti   ");
	get_argument_sizes(*(player->next_op + 1), (int)player->next_op[0], player);
}
