/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:53:17 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/24 15:07:09 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "bonus/bonus.h"

#ifdef BONUS

void	init()
{
	curses_init();
}

void	release()
{
}

#else

void	init()
{
}

void	release()
{
}

#endif
