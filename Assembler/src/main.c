/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:48:28 by lalves            #+#    #+#             */
/*   Updated: 2016/10/12 21:39:52 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "get_next_line.h"
#include <fcntl.h>

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
	while ((ret = get_next_line(src_fd, &line)))
	{
		if (ret > 0)
		{
			write(dst_fd, line, ft_strlen(line));
			write(dst_fd, "\n", 1);
		}
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
