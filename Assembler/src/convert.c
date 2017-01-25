/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 18:41:40 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/25 18:52:10 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "asm.h"
#include "get_next_line.h"


// in:  00000000 11101010 10000011 11110011
// out: 11110011 10000011 11101010 00000000
// 00 ea 83 f3
//

/*
** OsX est little-endian
** La VM est big-endian
*/

static void	write_magic_code(int fd)
{
	int a[1];

	a[0] = COREWAR_EXEC_MAGIC;
	write(fd, ((char *)a) + 3, 1);
	write(fd, ((char *)a) + 2, 1);
	write(fd, ((char *)a) + 1, 1);
	write(fd, ((char *)a), 1);

	// little_to_big_endian(COREWAR_EXEC_MAGIC);
}

/*
void little_to_big_endian()
{
}
*/

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

void		convert_file(char *src_path)
{
	int			src_fd;
	int			dst_fd;
	int			ret;
	char		*line;
	char		*dst_path;
	off_t		end_offset;

	dst_path = convert_path(src_path);
	if ((dst_fd = open(dst_path, O_WRONLY | O_CREAT, 0750)) < 0)
		exit(ERROR_OPEN_DST);
	if ((src_fd = open(src_path, O_RDONLY)) < 0)
		exit(ERROR_OPEN_SRC);
	ft_strdel(&dst_path);

	end_offset = lseek(src_fd, 0, SEEK_END);
	lseek(src_fd, 0, SEEK_SET);
	if (!end_offset)
		exit(ERROR_EMPTY_FILE);

	write_magic_code(dst_fd);
	while ((ret = get_next_line(src_fd, &line)))
	{
		if (ret > 0)
			parse_line(line, dst_fd);
		ft_strdel(&line);
	}
	close(src_fd);
	close(dst_fd);
}
