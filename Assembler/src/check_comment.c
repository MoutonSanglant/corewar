/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:03:45 by lalves            #+#    #+#             */
/*   Updated: 2017/01/30 20:08:18 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "get_next_line.h"

static int		check_comment_string(char *line)
{
	size_t i;

	i = 0;
	if (*line != '"') // pas de " pour debuter le com
		return (-1);
	line++;
	while (line[i] != '"')
	{
		if (!line[i]) // pas de " pour terminer le com
			return (-1);
		i++;
	}
	if (i > PROG_COMMENT_LENGTH) // com trop long
		return (comment_error());
	while (ft_isspace(line[i]))
		i++;
	if (line[i]) // si il y a de la merde apres le com
		return (-1);
	return (1);
}

static int		check_comment_cmd(char *line, size_t len)
{
	char *str;

	while (ft_isspace(*line))
		line++;
	str = ft_strsub(line, 0, len);
	if (ft_strcmp(str, COMMENT_CMD_STRING)) // pas de .comment
	{
		ft_strdel(&str);
		return (0);
	}
	ft_strdel(&str);
	line += len;
	while (ft_isspace(*line))
		line++;
	return (check_comment_string(line));
}

void			check_comment(int fd)
{
	char	*line;
	int		ret;
	int		comment_ret;
	int		comment;

	comment = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] != COMMENT_CHAR && ft_strcmp(line, ""))
		{
			comment_ret = check_comment_cmd(line, ft_strlen(COMMENT_CMD_STRING));
			if (comment_ret == -1)
			{
				ft_strdel(&line);
				exit(ERROR_SYNTAX);
			}
			if (comment_ret == -2)
			{
				ft_strdel(&line);
				exit(EXIT_FAILURE);
			}
			if (comment_ret == 1)
				comment++;
		}
		ft_strdel(&line);
	}
	if (ret == -1)
		exit(ERROR_READ_SRC);
	if (comment != 1)
		exit(ERROR_SYNTAX);
	lseek(fd, 0, SEEK_SET);
}
