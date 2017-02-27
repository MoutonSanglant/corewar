/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 18:41:40 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/25 21:22:21 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "asm.h"
#include "get_next_line.h"

static void	write_magic_code(int fd)
{
	int a[1];

	a[0] = COREWAR_EXEC_MAGIC;
	write(fd, ((char *)a) + 3, 1);
	write(fd, ((char *)a) + 2, 1);
	write(fd, ((char *)a) + 1, 1);
	write(fd, ((char *)a), 1);
}

static void	get_name_or_comment(char *line, char **name, char **comment)
{
	char	**tab;
	char	*tmp;
	size_t	i;

	line = ft_strtrim(line);
	tmp = line;
	tab = split_line(line);
	i = 0;
	if (!ft_strcmp(tab[0], NAME_CMD_STRING))
	{
		while (ft_isspace(*line))
			line++;
		line += ft_strlen(NAME_CMD_STRING);
		while (ft_isspace(*line))
			line++;
		i = ft_strchr(&(line[1]), '"') - line;
		*name = ft_strsub(line, 1, i - 1);
	}
	if (!ft_strcmp(tab[0], COMMENT_CMD_STRING))
	{
		while (ft_isspace(*line))
			line++;
		line += ft_strlen(COMMENT_CMD_STRING);
		while (ft_isspace(*line))
			line++;
		i = ft_strchr(&(line[1]), '"') - line;
		*comment = ft_strsub(line, 1, i - 1);
	}
	clean_split_line(&tab, &tmp);
}

static void	write_header(int fd, int dst_fd)
{
	char	*line;
	char	*s;
	int		ret;
	char	*name;
	char	*comment;

	name = NULL;
	comment = NULL;
	write_magic_code(dst_fd);
	while ((ret = get_next_line(fd, &line)))
	{
		s = ft_strtrim(line);
		if (s[0] != COMMENT_CHAR && s[0] != ';' && ft_strcmp(s, ""))
			get_name_or_comment(line, &name, &comment);
		ft_strdel(&line);
		ft_strdel(&s);
		if (name && comment)
			break ;
	}
	name_fn(dst_fd, name);
	comment_fn(dst_fd, comment);
	ft_strdel(&name);
	ft_strdel(&comment);
}

static int	space_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

void		convert_file(char *src_path)
{
	int			ret;
	char		*line;
	char		*dst_path;
	t_env		*env;

	env = init_env(src_path);
	dst_path = convert_path(src_path);
	if (!check_invalid_file(env))
		exit(ERROR_SYNTAX);
	check_cmd_length(env->src_fd);
	check_label_fill(env);
	if ((env->dst_fd = open(dst_path, O_WRONLY | O_CREAT, 0750)) < 0)
		exit(ERROR_OPEN_DST);
	ft_printf("Writing output program to %s\n", dst_path);
	ft_strdel(&dst_path);
	write_header(env->src_fd, env->dst_fd);
	while ((ret = get_next_line(env->src_fd, &line)))
	{
		if (ret > 0 && !space_line(line))
			parse_line(line, env);
		ft_strdel(&line);
	}
	write_prog_size(env->dst_fd);
/*	ft_printf("\n\nDeclare :\n");
	while (env->declare)
	{
		ft_printf("label = %s, pos = %i\n", env->declare->label, env->declare->pos);
		env->declare = env->declare->next;
	}
	ft_printf("\n\n\nUse :\n");
	while (env->use)
	{
		ft_printf("label = %s, pos = %i, pos_write = %i\n", env->use->label, env->use->pos, env->use->pos_to_write);
		env->use = env->use->next;
	}
	exit(1);*/
	write_labels(env);
	clear_env(&env);
}
