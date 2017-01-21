/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 13:58:14 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/21 16:59:53 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "corewar.h"

static int		valid_header(int fd, t_player *player)
{
	char	buf[sizeof(header_t)];
	ssize_t	rcount;
	header_t	header;

	rcount = read(fd, (void *)buf, sizeof(header_t));
	if (rcount < 0)
		return (0);
	ft_memcpy(&header, buf, sizeof(header_t));
	player->name = ft_strdup(header.prog_name);
	player->comment = ft_strdup(header.prog_name);
	if (bytes_to_int((char *)&header.magic) != COREWAR_EXEC_MAGIC)
		return (0);
	ft_printf("* Player %i, weighing %i bytes, \"%s\", (\"%s\") !\n", player->number, bytes_to_int((char *)&header.prog_size), header.prog_name, header.comment);
	return (1);
}

static void	read_champion_file(char *path, t_player *player)
{
	//char	buf[BUFF_SIZE];
	off_t	end_offset;
	int		fd;

	if ((fd = open(path, O_RDONLY)) < 0)
		error(ERRNO_OPEN, path);
	end_offset = lseek(fd, 0, SEEK_END);
	if (end_offset < (off_t)sizeof(header_t))
		error(ERRNO_SIZE, path);
	lseek(fd, 0, SEEK_SET);
	if(!valid_header(fd, player))
		error(ERRNO_HEADER, path);
	close(fd);
	ft_printf("Bytecode valide.\n");
}

void	read_champions(int count, char **av)
{
	int		i;

	g_corewar.players = (t_player *)malloc(sizeof(t_player) * count);

	i = 0;
	while (i < count)
	{
		g_corewar.players[i].number = i + 1;
		read_champion_file(av[i], &g_corewar.players[i]);
		i++;
	}
}
