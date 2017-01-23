/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:53:17 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/23 20:08:04 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/bonus.h"

#ifdef BONUS

void	init()
{
	curses_init();
}

void	release()
{
	curses_release();
}

#else

void	init()
{
}

void	release()
{
}

#endif
