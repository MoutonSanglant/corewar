/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:01:21 by lalves            #+#    #+#             */
/*   Updated: 2017/01/30 20:32:46 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "get_next_line.h"

static int		check_command_before_name(char *line)
{
//  ???
}

static int		check_name_string(char *line)
{
	size_t i;

	i = 0;
	if (*line != '"') // pas de " pour debuter le nom
		return (-1);
	line++;
	while (line[i] != '"')
	{
		if (!line[i]) // pas de " pour terminer le nom
			return (-1);
		i++;
	}
	if (i > PROG_NAME_LENGTH) // nom trop long
		return (name_error());
	while (ft_isspace(line[i]))
		i++;
	if (line[i]) // si il y a de la merde apres le nom
		return (-1);
	return (1);
}

static int		check_name_cmd(char *line, size_t len)
{
	char	*str;

	while (ft_isspace(*line))
		line++;
	str = ft_strsub(line, 0, len);
	if (ft_strcmp(str, NAME_CMD_STRING)) // pas de .name
	{
		ft_strdel(&str);
		return (check_command_before_name(line)); // ???
	}
	ft_strdel(&str);
	line += len;
	while (ft_isspace(*line))
		line++;
	return (check_name_string(line));
}

void			check_name(int fd)
{
	char	*line;
	int		ret;
	int		name_ret;
	int		name;

	name = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] != COMMENT_CHAR && ft_strcmp(line, ""))
		{
			name_ret = check_name_cmd(line, ft_strlen(NAME_CMD_STRING));
			if (name_ret == -1)
			{
				ft_strdel(&line);
				exit(ERROR_SYNTAX);
			}
			if (name_ret == -2)
			{
				ft_strdel(&line);
				exit(EXIT_FAILURE);
			}
			if (name_ret == 1)
				name++;
		}
		ft_strdel(&line);
	}
	if (ret == -1)
		exit(ERROR_READ_SRC);
	if (name != 1)
		exit(ERROR_SYNTAX);
	lseek(fd, 0, SEEK_SET);
}
