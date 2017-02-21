/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 21:27:30 by lalves            #+#    #+#             */
/*   Updated: 2017/02/21 22:23:10 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	write_fn(int fd, off_t pos, int nb, int byte_to_write) // write nb sur byte_to_write a l'offset pos.
{

}

void		write_labels(t_env *env)
{
	t_label *d;
	t_label *u;

	d = env->declare;
	u = env->use;
	while (u)
	{
		while (d)
		{
			if (!ft_strcmp(d->label, u->label))
			{
				write_fn(env->dst_fd, u->pos, u->pos - d->pos, u->byte);
			}
			d = d->next;
		}
		u = u->next;
	}
}
