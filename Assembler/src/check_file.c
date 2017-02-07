/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:00:55 by lalves            #+#    #+#             */
/*   Updated: 2017/02/07 19:15:57 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "get_next_line.h"


static int		check_name_string(char *str, int other)
{
	char	*s;
	int		i;

	if (other)
		return (-1);
	s = ft_strtrim(str);
	i = 0;
	if (ft_strlen(s) - 2 > PROG_NAME_LENGTH)
	{
		ft_strdel(&s);
		return (name_error());
	}
	if (s[i] != '"' || s[ft_strlen(s) - 1] != '"')
	{
		ft_strdel(&s);
		return (-1);
	}
	ft_strdel(&s);
	return (1);
}

static int		check_name(int fd)
{
	char	*line;
	char	*s;
	int		ret;
	int		other;

	other = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		s = ft_strtrim(line);
		if (s[0] != COMMENT_CHAR && ft_strcmp(s, ""))
		{
			if (!ft_strncmp(s, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))) // si on a bien name
			{
				ret	= check_name_string(s + ft_strlen(NAME_CMD_STRING), other)
				ft_strdel(&line);
				ft_strdel(&s);
				lseek(fd, 0, SEEK_SET);
				return (ret);
			}
			else
				return ;
		}
		ft_strdel(&s);
		ft_strdel(&line);
	}
	if (ret == -1)
		exit(ERROR_READ_SRC);
	lseek(fd, 0, SEEK_SET);
}

int			check_invalid_file(int fd)
{
	int ret;

	ret = check_name(fd);
	if (ret == 1)
		of ()
	check_comment(fd);
	check_order(fd);
}
