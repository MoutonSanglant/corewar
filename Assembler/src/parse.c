/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 18:45:06 by tdefresn          #+#    #+#             */
/*   Updated: 2016/10/16 19:11:17 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_op_conv		g_opcode_list[3] =
{
	{"live", &live_fn},
	{NAME_CMD_STRING, &name_fn},
	{NULL, NULL}
};

void	parse_line(char *line, int fd)
{
	t_op_conv	opcode;
	char		**split;
	int			i;

	//write(dst_fd, line, ft_strlen(line));
	//write(dst_fd, "\n", 1);
	split = ft_strsplit(line, ' ');
	if (!split[0])
		return ;

	i = 0;
	while ((opcode = g_opcode_list[i]).name)
	{
		if (ft_strequ(split[0], opcode.name))
		{
			ft_printf("opcode: %s \n", opcode.name);
			opcode.fn(fd, &split[1]);
			return ;
		}
		i++;
	}
}
