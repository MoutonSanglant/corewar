/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:30:12 by tdefresn          #+#    #+#             */
/*   Updated: 2016/10/16 17:16:39 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		error(char *str, int errno)
{
	char			*s;
	unsigned int	i;

	i = 0;
	s = str;
	while (*s++)
		i++;
	write(1, str, i);
	return (errno);
}
