/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 21:27:30 by lalves            #+#    #+#             */
/*   Updated: 2017/02/22 20:26:38 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_label_use_offset(char *arg, t_env *env)
{
	t_label *lst;
	size_t	i;
	char	*tmp;

	lst = env->use;
	i = 0;
	tmp = arg;
	arg = ft_strchr(arg, LABEL_CHAR);
	if (!arg)
		return ;
	arg++;
	while (ft_strchr(LABEL_CHARS, arg[i]))
		i++;
	arg = ft_strsub(arg, 0, i);
	while (lst)
	{
		if (!ft_strcmp(arg, lst->label) && !(lst->pos))
		{
			lst->pos = lseek(env->dst_fd, 0, SEEK_CUR);
			break ;
		}
		lst = lst->next;
	}
	ft_strdel(&arg);
}

static void	write_fn(int fd, off_t pos, int *nb, int byte_to_write)
{
	lseek (fd, pos, SEEK_SET);
	while (byte_to_write >= 0)
	{
		write(fd, ((char*)nb) + byte_to_write, 1);
		byte_to_write--;
	}
}

static t_label	*del_node(t_label **u)
{
	t_label *tmp;

	tmp = (*u)->next;
	ft_strdel(&((*u)->label));
	free(*u);
	return (tmp);
}

void	write_labels(t_env *env)
{
	t_label *d;
	t_label *u;
	int		nb;

	d = env->declare;
	u = env->use;
	while (u)
	{
		while (d)
		{
			if (!ft_strcmp(d->label, u->label))
			{
				nb = d->pos - u->pos;
				write_fn(env->dst_fd, u->pos_to_write, &nb, u->bytes - 1);
				d = env->declare;
				break ;
			}
			d = d->next;
		}
		u = del_node(&u);
	}
}
