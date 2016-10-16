/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <akopera@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:48:28 by tdefresn          #+#    #+#             */
/*   Updated: 2016/10/16 15:44:58 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "get_next_line.h"
#include <fcntl.h>

void name_fn(int fd, char **split)
{
	int i;
	i = 0;
	while (split[i])
	{
		write(fd, split[i], ft_strlen(split[i]));
		if (split[i + 1])
			write(fd, " ", 1);
		i++;
	}
}

void write_magic_code(int fd)
{
	int a[1];
	a[0] = COREWAR_EXEC_MAGIC;

	write(fd, ((char *)a) + 3, 1);
	write(fd, ((char *)a) + 2, 1);
	write(fd, ((char *)a) + 1, 1);

	write(fd, ((char *)a), 1);
}


void live_fn(int fd, char **split)
{
	(void)fd;
	(void)split;

}


typedef struct	s_op_fn
{
	char	*name;
	void	(*fn)(int, char **);
}				t_op_fn;

t_op_fn		opcode_fn[3] =
{
	{"live", &live_fn},
	{NAME_CMD_STRING, &name_fn},
	{NULL, NULL}
};

int		error(char *str)
{
	ft_putendl(str);
	return (-1);
}

char	*convert_path(char *path)
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

void	parse_line(char *line, int fd)
{
	char	**split;
	int		i;

	(void)fd;
	i = 0;
	//write(dst_fd, line, ft_strlen(line));
	//write(dst_fd, "\n", 1);
	split = ft_strsplit(line, ' ');
	if (!split[0])
		return ;

	while (opcode_fn[i].name)
	{
		ft_printf("printsplit: %s // %s\n", opcode_fn[i].name, split[0]);
		if (ft_strequ(split[0], opcode_fn[i].name))
		{
			opcode_fn[i].fn(fd, &split[1]);
			return ;
		}
		i++;
	}
}

void	parse_source_file(char *src_path)
{
	int		src_fd;
	int		dst_fd;
	int		ret;
	char	*line;
	char	*dst_path;


	dst_path = convert_path(src_path);
	if ((dst_fd = open(dst_path, O_WRONLY | O_CREAT, 0750)) < 0)
		exit(error(ERROR_OPEN_DST));
	if ((src_fd = open(src_path, O_RDONLY)) < 0)
		exit(error(ERROR_OPEN_SRC));

	write_magic_code(dst_fd);
	while ((ret = get_next_line(src_fd, &line)))
	{
		if (ret > 0)
			parse_line(line, dst_fd);
		ft_strdel(&line);
	}
	ft_strdel(&dst_path);
	close(src_fd);
	close(dst_fd);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (error(USAGE));
	parse_source_file(av[1]);
	return (0);
}
