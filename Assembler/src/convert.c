/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 18:41:40 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/30 18:28:37 by lalves           ###   ########.fr       */
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
	int		i;

	line = ft_strtrim(line);
	tab = split_line(line);
	i = 0;
	if (!ft_strcmp(tab[0], NAME_CMD_STRING))
	{
		while (ft_isspace(line[i]))
			i++;
		i += ft_strlen(NAME_CMD_STRING);
		while (ft_isspace(line[i]))
			i++;
		*name = ft_strsub(&(line[i]), 1, ft_strlen(&(line[i])) - 2);
	}
	if (!ft_strcmp(tab[0], COMMENT_CMD_STRING))
	{
		while (ft_isspace(line[i]))
			i++;
		i += ft_strlen(COMMENT_CMD_STRING);
		while (ft_isspace(line[i]))
			i++;
		*comment = ft_strsub(&(line[i]), 1, ft_strlen(&(line[i])) - 2);
	}
	ft_strdel(&tab[0]);
	ft_strdel(&tab[1]);
	free(tab);
	ft_strdel(&line);
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
		if (s[0] != COMMENT_CHAR && ft_strcmp(s, ""))
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

static char	*convert_path(char *path)
{
	char	*new_path;
	size_t	len;

	len = ft_strlen(path);
	new_path = ft_strnew(len + 2);
	new_path = ft_strcpy(new_path, path);
	new_path[len - 1] = 'c';
	new_path[len] = 'o';
	new_path[len + 1] = 'r';
	new_path[len + 2] = '\0';
	return (new_path);
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

t_label		*init_label(void)
{
	t_label *new;

	new = malloc(sizeof(t_label));
	if (!new)
		exit(ERROR_MALLOC);
	new->label = NULL;
	new->pos = 0;
	new->next = NULL;
	return (new);
}

void		convert_file(char *src_path)
{
	int			src_fd;
	int			dst_fd;
	int			ret;
	char		*line;
	char		*dst_path;
	t_label		*declare;
	t_label		*use;

	declare = init_label();
	use = init_label();
	dst_path = convert_path(src_path);
	if ((src_fd = open(src_path, O_RDONLY)) < 0)
		exit(ERROR_OPEN_SRC);
	if (!check_invalid_file(src_fd, declare, use)) // si erreur de syntaxe
		exit(ERROR_SYNTAX);
	check_cmd_length(src_fd);
	if ((dst_fd = open(dst_path, O_WRONLY | O_CREAT, 0750)) < 0)
		exit(ERROR_OPEN_DST);
	ft_printf("Writing output program to %s\n", dst_path);
	ft_strdel(&dst_path);
	write_header(src_fd, dst_fd);
	while ((ret = get_next_line(src_fd, &line)))
	{
		if (ret > 0 && !space_line(line))
			parse_line(line, dst_fd);
		ft_strdel(&line);
	}
	write_prog_size(dst_fd);
	close(src_fd);
	close(dst_fd);
}
