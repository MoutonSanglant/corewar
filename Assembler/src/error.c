/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 17:10:12 by tdefresn          #+#    #+#             */
/*   Updated: 2016/10/16 17:14:51 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		error(char *str, int errno)
{
	char			*s;
	unsigned int	i;

	s = str;
	i = 0;
	while (*s++)
		i++;
	write(1, str, i);
	return (errno);
}
