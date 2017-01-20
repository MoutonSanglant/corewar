/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 13:58:14 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/20 21:42:49 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "corewar.h"

static int		valid_magic_code(int fd, char *buf)
{
	ssize_t	rcount;
	int		magic;
	off_t	cur_offset;

	cur_offset = 0;
	while (cur_offset < 4)
	{
		rcount = read(fd, (void *)buf, 4);
		//ft_printf("read: %i\n", rcount);
		cur_offset = lseek(fd, 0, SEEK_CUR);
		//ft_printf("offset: %i\n", cur_offset);

		//if (rcount < 4)
		//	exit(ERROR_INVALID_FILETYPE);

		magic = bytes_to_int(buf);

		//ft_printf("magic code: %x%x%x%x\n", buf[0] & 0xff, buf[1] & 0xff, buf[2] & 0xff, buf[3] & 0xff);
		//ft_printf("magic code: %x\n", magic);
		if (magic != COREWAR_EXEC_MAGIC)
			return (0);
	}
	return (1);
}

static void			read_binary(char *path)
{
	//ssize_t	rcount;
	int		fd;
	char	buf[BUFF_SIZE];
	off_t	end_offset;

	if ((fd = open(path, O_RDONLY)) < 0)
		error(ERRNO_OPEN, NULL);

	end_offset = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	if (!end_offset)
		error(ERRNO_EMPTY, NULL);

	if (!valid_magic_code(fd, buf))
		error(ERRNO_HEADER, path);
	ft_printf("Bytecode valide.\n");
	/*
	while ((rcount = read(fd, buf, BUFF_SIZE)))
	{
	}
	*/
}

static void	parse_champion_file(char *path)
{
	int		fd;
	off_t	end_offset;

	if ((fd = open(path, O_RDONLY)) < 0)
		error(ERRNO_OPEN, path);
	end_offset = lseek(fd, 0, SEEK_END);

	close(fd);
	if (end_offset < (off_t)sizeof(header_t))
		error(ERRNO_SIZE, path);
	read_binary(path);
}

void	read_champions(int count, char **av)
{
	int		i;

	i = 0;
	while (i < count)
	{
		parse_champion_file(av[i]);
		i++;
	}
}
