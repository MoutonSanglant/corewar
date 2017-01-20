/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 18:45:06 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/20 18:04:56 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_op_conv		g_opcode_list[19] =
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
	{ NAME_CMD_STRING, 17, &name_fn },
	{ COMMENT_CMD_STRING, 18, &comment_fn },
	{ NULL, 0, NULL }
};

static char				**split_line(char *line)
{
	char	**tab;
	char	*tmp;
	size_t	i;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * 2);
	if (!tab)
		memory_error();
	while (ft_isspace(*line))
		line++;
	while (ft_isalpha(line[i]) || line[i] == '.')
		i++;
	tab[0] = ft_strsub(line, 0, i); // tab[0] => opcode / name / comment
	line += i;
	while (ft_isspace(*line))
		line++;
	tab[1] = ft_strdup(line); // tab[1] => argument
	if (!ft_strcmp(tab[0], NAME_CMD_STRING) || !ft_strcmp(tab[0], COMMENT_CMD_STRING)) // trim "" pour name / comment
	{
		tmp = tab[1];
		tab[1] = ft_strsub(tab[1], 1, ft_strlen(tab[1]) - 2);
		ft_strdel(&tmp);
	}
	return (tab);
}

void						parse_line(char *line, int fd)
{
	char		**tab;
	int			i;

	i = 0;
	if (line[0] != COMMENT_CHAR)
	{
		tab = split_line(line);
		while (g_opcode_list[i]->name)
		{
			if (!ft_strcmp(tab[0], g_opcode_list[i]->name))
			{
				ft_printf("opcode found: %s\n", tab[0]);
				g_opcode_list[i]->fn(fd, tab[1]);
				ft_strdel(&(tab[0]));
				ft_strdel(&(tab[1]));
				free(tab);
				return ;
			}
			i++;
		}
		ft_strdel(&(tab[0]));
		ft_strdel(&(tab[1]));
		free(tab);
		ft_putendl("ceci n'est pas un opcode :(");
	}
}
