/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:54:39 by lalves            #+#    #+#             */
/*   Updated: 2017/02/07 16:35:34 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		count_words(char *str)
{
	char	*s;
	size_t	i;
	size_t	count;

	s = ft_strtrim(str);
	i = 0;
	count = 1;
	while (s[i])
	{
		if (ft_isspace(s[i]))
		{
			while (ft_isspace(s[i]))
				i++;
			count++;
		}
		else
			i++;
	}
	ft_strdel(&s);
	return (count);
}

char			**split_line(char *str)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	j = 0;
	tab = (char**)malloc(sizeof(char*) * (count_words(str) + 1));
	if (!tab)
		return (NULL);
	while (ft_isspace(*str))
		str++;
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			tab[j] = ft_strsub(str, 0, i);
			while (str[i] && ft_isspace(str[i]))
				i++;
			str = &str[i];
			j++;
			i = 0;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
