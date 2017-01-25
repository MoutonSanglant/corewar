/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 13:58:14 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/25 17:41:21 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "corewar.h"

static int		load_header(int fd, t_player *player)
{
	char		buf[sizeof(header_t)];
	ssize_t		rcount;
	header_t	header;

	lseek(fd, 0, SEEK_SET);
	rcount = read(fd, buf, sizeof(header_t));
	if (rcount < 0)
		return (0);
	ft_memcpy(&header, buf, sizeof(header_t));

	player->name = ft_strdup(header.prog_name);
	player->comment = ft_strdup(header.comment);

	player->prog_size = bytes_to_int((char *)&header.prog_size);
	player->bytecode = ft_memalloc(player->prog_size);

	if (bytes_to_int((char *)&header.magic) != COREWAR_EXEC_MAGIC)
		return (0);
	return (1);
}

static int		load_bytecode(int fd, t_player *player)
{
	off_t	offset;
	ssize_t	rcount;
	int		size;
	char	*b;

	b = NULL;
	size = player->prog_size;
	offset = lseek(fd, 0, SEEK_CUR);
	ft_printf("prog size: %u\n", size);
	if (lseek(fd, 0, SEEK_END) != (off_t)(sizeof(header_t) + size))
		return (0);
	lseek(fd, offset, SEEK_SET);
	b = (char *)malloc(size);
	rcount = read(fd, b, size);
	ft_printf("read return: %i\n", rcount);
	if (rcount < 0)
		return (0);
	ft_memcpy(player->bytecode, b, size);
	//ft_memcpy(bytecode, b, size);
	//player->bytecode = bytecode;
	free(b);
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

void	read_champions(int count, char **av)
{
	t_player	*player;
	int			i;

	// alocate 'count' players
	i = 0;
	g_corewar.player_count = count;
	g_corewar.players = ft_memalloc(sizeof(t_player) * count);
	while (i < count)
	{
		player = &g_corewar.players[i];
		ft_printf("[DEBUG] player %i\n", i);
		read_champion_file(av[i], player);
		player->number = i + 1;
		// TODO
		// deplacer lorsque tous les champions sont OK
		ft_printf(STR_PLAYER_SUM, (int)player->number, player->prog_size, player->name, player->comment);
		i++;
	}
}
