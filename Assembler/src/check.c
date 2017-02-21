/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 07:55:12 by lalves            #+#    #+#             */
/*   Updated: 2017/02/21 09:48:08 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "get_next_line.h"

static char	*op_tab[17] =
{
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

static int	check_comment(char *line, int *comment)
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

int			type_of_line(char *line)
{
	int i;

	i = 0;
	if (!ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		return (1);
	if (!ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		return (2);
	while (op_tab[i])
	{
		if (!ft_strncmp(line, op_tab[i], ft_strlen(op_tab[i])))
			return (3);
		i++;
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == LABEL_CHAR)
			return (4);
		if (!ft_strchr(LABEL_CHARS, line[i]))
			return (0);
		i++;
	}
	return (0);
}

static int	check_invalid_line(char *line, int type, t_env *env)
{
	if (type == 4)
	{
		line = save_label(line, env);
		if (!line)
			return (1);
		type = type_of_line(line);
	}
	if (type == 1)
		return (check_name(line + ft_strlen(NAME_CMD_STRING), &(env->name)));
	if (type == 2)
		return (check_comment(line + ft_strlen(COMMENT_CMD_STRING), &(env->comment)));
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
