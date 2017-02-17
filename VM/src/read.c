/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 13:58:14 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/17 20:12:36 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "corewar.h"

static int	load_header(int fd, t_player *player)
{
	ssize_t		rcount;
	header_t	header;
	int			magic;

	magic = 0;
	lseek(fd, 0, SEEK_SET);
	rcount = read(fd, (char *)&header, sizeof(header_t));
	if (rcount < 0)
		return (0);
	swap_endianess((char *)&magic, (char *)&header.magic, sizeof(int));
	if (magic != COREWAR_EXEC_MAGIC)
		return (0);
	player->name = ft_strdup(header.prog_name);
	player->comment = ft_strdup(header.comment);
	swap_endianess((char *)&player->prog_size, (char *)&header.prog_size,
																sizeof(int));
	return (1);
}

static int	load_bytecode(int fd, t_player *player)
{
	off_t	offset;
	ssize_t	rcount;
	int		size;

	size = player->prog_size;
	player->bytecode = ft_memalloc(player->prog_size);
	offset = lseek(fd, 0, SEEK_CUR);
	if (lseek(fd, 0, SEEK_END) != (off_t)(sizeof(header_t) + size))
		return (0);
	lseek(fd, offset, SEEK_SET);
	rcount = read(fd, player->bytecode, size);
	if (rcount < 0)
		return (0);
	return (1);
}

static void	read_champion_file(char *path, t_player *player)
{
	int		fd;
	off_t	end_offset;

	if ((fd = open(path, O_RDONLY)) < 0)
		error(ERRNO_OPEN, path);
	end_offset = lseek(fd, 0, SEEK_END);
	if (end_offset < (off_t)sizeof(header_t))
		error(ERRNO_CHAMP_FILE_TOO_SMALL, path);
	if (end_offset - (off_t)sizeof(header_t) > CHAMP_MAX_SIZE)
		error_max_size(path, end_offset - (off_t)sizeof(header_t));
	if (!load_header(fd, player))
		error(ERRNO_HEADER, path);
	if (!load_bytecode(fd, player))
		error(ERRNO_PROG_SIZE, path);
	close(fd);
}

static int	get_valid_number(int count, int number)
{
	t_player	*player;
	int			i;

	i = 0;
	while (i < count)
	{
		player = &g_corewar.players[i];
		if (number == player->number)
			error(ERRNO_CHAMP_NBR, NULL);
		i++;
	}
	if (number < 0)
	{
		i = 0;
		number = count + 1;
		while (i < count)
		{
			player = &g_corewar.players[i];
			if (number == player->number)
				number--;
			i++;
		}
	}
	return (number);
}

void		read_champion(char *av, int number)
{
	static int	count = 0;
	t_player	*player;

	number = get_valid_number(count, number);
	count++;
	g_corewar.player_count = count;
	g_corewar.players = (t_player *)realloc(g_corewar.players,
			sizeof(t_player) * count);
	player = &g_corewar.players[count - 1];
	read_champion_file(av, player);
	player->number = number;
	player->id = count;
}
