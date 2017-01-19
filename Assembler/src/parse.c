/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 18:45:06 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/19 21:09:36 by lalves           ###   ########.fr       */
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
	{ NULL, NULL }
};

static void				**split_line(char *line)
{
	char	*tab[2];
	size_t	i;

	i = 0;
	while (ft_isspace(*line))
		line++;
	while (ft_isalpha(line[i]))
		i++;
	tab[0] = ft_strsub(line, 0, i); // tab[0] => opcode
	line += i;
	while (ft_isspace(*line))
		line++;
	tab[1] = ft_strdup(line); // tab[1] => instruction
	return (tab);
}

void					parse_line(char *line, int fd)
{
	char		**tab;
	int			i;

	i = 0;
	str = split_line(line);
	while (i > 17)
	{
		if (!ft_strcmp(tab[0], g_opcode_list[i]->name))
		{
			ft_printf("opcode found: %s \n", g_opcode_list[i]->name);
			g_opcode_list[i]->fn(g_opcode_list[i]->opcode_nb, tab[1]);
			return ;
		}
		i++;
	}
	ft_putendl("ceci n'est pas un opcode :(");
}
/*	while ((opcode = &g_opcode_list[i])->name)
	{
		if (!ft_strcmp(tab[0], opcode->name))
		{
			ft_printf("opcode found: %s \n", opcode->name);
			opcode->fn(fd, &split[1]);
			return ;
		}
		i++;
	}
*/
