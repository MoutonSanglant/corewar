/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 18:45:06 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/25 21:44:08 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op_conv			*get_opcode(int i)
{
	static t_op_conv	opcode_list[17] = {
	{ "live", 1, &live_fn },
	{ "ld", 2, &ld_fn },
	{ "st", 3, &st_fn },
	{ "add", 4, &add_fn },
	{ "sub", 5, &sub_fn },
	{ "and", 6, &and_fn },
	{ "or", 7, &or_fn },
	{ "xor", 8, &xor_fn },
	{ "zjmp", 9, &zjmp_fn },
	{ "ldi", 10, &ldi_fn },
	{ "sti", 11, &sti_fn },
	{ "fork", 12, &fork_fn },
	{ "lld", 13, &lld_fn },
	{ "lldi", 14, &lldi_fn },
	{ "lfork", 15, &lfork_fn },
	{ "aff", 16, &aff_fn },
	{ NULL, 0, NULL }
	};

	return (&opcode_list[i]);
}

void				clean_split_line(char ***tab, char **line)
{
	free((*tab)[0]);
	free((*tab)[1]);
	free(*tab);
	free(*line);
}

static void			get_label_declare_offset(char *line, t_env *env)
{
	t_label *lst;

	lst = env->declare;
	line = ft_strsub(line, 0, ft_strlen(line) - 1);
	while (lst)
	{
		if (!ft_strcmp(line, lst->label))
		{
			lst->pos = lseek(env->dst_fd, 0, SEEK_CUR);
			ft_strdel(&line);
			return ;
		}
		lst = lst->next;
	}
	ft_strdel(&line);
}

void				parse_line(char *line, t_env *env)
{
	char		**tab;
	t_op_conv	*opcode_list;
	int			i;

	i = 0;
	line = ft_strtrim(line);
	if ((line[0] != COMMENT_CHAR) && (ft_strcmp(line, "")))
	{
		tab = split_line(line);
		if (!tab)
		{
			get_label_declare_offset(line, env);
			ft_strdel(&line);
			return ;
		}
		while ((opcode_list = get_opcode(i)) && opcode_list->name)
		{
			if (!ft_strcmp(tab[0], opcode_list->name))
			{
				opcode_list->fn(env, tab[1], opcode_list->code);
				return (clean_split_line(&tab, &line));
			}
			i++;
		}
		get_label_declare_offset(tab[0], env);
		parse_line(&(line[ft_strlen(tab[0])]), env);
		clean_split_line(&tab, &line);
	}
}
