/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:16:47 by lalves            #+#    #+#             */
/*   Updated: 2017/02/21 16:33:35 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	is_label(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == LABEL_CHAR)
			return (4);
		if (!ft_strchr(LABEL_CHARS, line[i]))
			return (0);
		i++;
	}
	return (0);
}

int			type_of_line(char *line)
{
	int		i;
	char	**op_tab;

	i = 0;
	if (!ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		return (1);
	if (!ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		return (2);
	while ((op_tab = get_op_tab(i)) && *op_tab)
	{
		if (!ft_strncmp(line, *op_tab, ft_strlen(*op_tab)))
		{
			if (ft_isspace(line[ft_strlen(*op_tab)]))
				return (3);
		}
		i++;
	}
	return (is_label(line));
}

char		*save_label(char *line, t_env *env)
{
	size_t	i;
	t_label	*new;

	i = 0;
	while (line[i] != LABEL_CHAR)
		i++;
	new = init_label(line, i);
	new->next = env->declare;
	env->declare = new;
	if (line[i + 1])
		return (&(line[i + 1]));
	return (NULL);
}
