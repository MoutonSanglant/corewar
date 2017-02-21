/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 07:55:12 by lalves            #+#    #+#             */
/*   Updated: 2017/02/21 16:41:31 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "get_next_line.h"

char		**get_op_tab(int i)
{
	static char	*op_tab[17] = {
	"live",
	"ld",
	"st",
	"add",
	"sub",
	"and",
	"or",
	"xor",
	"zjmp",
	"ldi",
	"sti",
	"fork",
	"lld",
	"lldi",
	"lfork",
	"aff",
	NULL
	};

	return (&op_tab[i]);
}

static int	check_name(char *line, int *name)
{
	char	*s;

	s = ft_strtrim(line);
	if (s[0] != '"' || s[ft_strlen(s) - 1] != '"')
	{
		ft_strdel(&s);
		return (0);
	}
	(*name)++;
	ft_strdel(&s);
	return (1);
}

static int	check_com(char *line, int *comment)
{
	char	*s;

	s = ft_strtrim(line);
	if (s[0] != '"' || s[ft_strlen(s) - 1] != '"')
	{
		ft_strdel(&s);
		return (0);
	}
	(*comment)++;
	ft_strdel(&s);
	return (1);
}

static int	check_invalid_line(char *line, int type, t_env *env)
{
	int ret;

	if (type == 4)
	{
		line = save_label(line, env);
		while (line && ft_isspace(*line))
			line++;
		if (!line)
			return (1);
		type = type_of_line(line);
	}
	if (type == 1)
		return (check_name(line + ft_strlen(NAME_CMD_STRING), &(env->name)));
	if (type == 2)
	{
		ret = check_com(line + ft_strlen(COMMENT_CMD_STRING), &(env->comment));
		return (ret);
	}
	if (!type || env->name < 1 || env->comment < 1)
		return (0);
	if (type == 3)
		return (check_opcode(line, env));
	return (1);
}

int			check_invalid_file(t_env *env)
{
	char	*line;
	char	*s;
	int		ret;

	while ((ret = get_next_line(env->src_fd, &line)))
	{
		s = ft_strtrim(line);
		if (s[0] != COMMENT_CHAR && ft_strcmp(s, ""))
		{
			if (!check_invalid_line(s, type_of_line(s), env))
			{
				ft_strdel(&line);
				ft_strdel(&s);
				return (0);
			}
		}
		ft_strdel(&line);
		ft_strdel(&s);
	}
	if (ret == -1)
		exit(ERROR_READ_SRC);
	if (env->name != 1 || env->comment != 1 || env->opcode < 1)
		return (0);
	lseek(env->src_fd, 0, SEEK_SET);
	return (1);
}
