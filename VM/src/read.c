/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 13:58:14 by tdefresn          #+#    #+#             */
/*   Updated: 2016/10/16 16:23:46 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "corewar.h"


static void		read_magic_code(int fd, char *buf)
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
			exit(ERROR_INVALID_FILETYPE);
	}
}

void			read_binary(char *path)
{
	//ssize_t	rcount;
	int		fd;
	char	buf[BUFF_SIZE];
	off_t	end_offset;

	if ((fd = open(path, O_RDONLY)) < 0)
		exit(ERROR_OPEN);

	end_offset = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	if (!end_offset)
		exit(ERROR_EMPTY_FILE);

	read_magic_code(fd, buf);
	ft_printf("Bytecode valide.\n");
	/*
	while ((rcount = read(fd, buf, BUFF_SIZE)))
	{
	}
	*/
}
