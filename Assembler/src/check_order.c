/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:13:30 by lalves            #+#    #+#             */
/*   Updated: 2017/01/30 20:32:45 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "get_next_line.h"

void			check_order(int fd)
{
	char	*line;
	int		ret;
	int		name;
	int		comment;

	name = 0;
	comment = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line_is_name)
			name++;
		else if (line_is_comment)
	}
}
