/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 18:45:06 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/30 16:58:50 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_op_conv		g_opcode_list[17] =
{
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

void						parse_line(char *line, int fd)
{
	char		**tab;
	int			i;

	i = 0;
	line = ft_strtrim(line);
	if ((line[0] != COMMENT_CHAR) && (ft_strcmp(line, "")))
	{
		tab = split_line(line);
		if (!tab) // on est sur un label
		{
			ft_strdel(&line);
			return ;
		}
		while (g_opcode_list[i].name)
		{
			if (!ft_strcmp(tab[0], g_opcode_list[i].name))
			{
				g_opcode_list[i].fn(fd, tab[1], g_opcode_list[i].code);
				break ;
			}
			i++;
		}
		ft_strdel(&(tab[0]));
		ft_strdel(&(tab[1]));
		ft_strdel(&line);
		free(tab);
	}
}
