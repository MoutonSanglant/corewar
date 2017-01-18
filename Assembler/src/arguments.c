/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 23:20:52 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/18 16:52:50 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	parse_arg(char *arg, const t_args *arg_list, t_flags *flags)
{
	int		i;

	i = 0;
	if (arg[0] != '-')
		return (1);
	while (i < ARGS_LIST_SIZE)
	{
		if (arg[1] == '-')
		{
			if (!ft_strcmp(&arg[2], arg_list[i].string))
				*flags |= arg_list[i].flag;
		}
		else if (ft_strchr(arg, arg_list[i].c))
				*flags |= arg_list[i].flag;
		i++;
	}
	return (0);
}

static int	parse(int argc, char **argv, t_flags *flags, const t_args *arg_list)
{
	int		count;
	int		i;

	i = 0;
	count = 1;
	*flags = 0;
	while (++i < argc)
	{
		if (parse_arg(argv[i], arg_list, flags))
			break ;
		count++;
	}
	return (count);
}

int			parse_arguments(int argc, char **argv, t_flags *flags)
{
	static const t_args	arg_list[ARGS_LIST_SIZE] =
	{
		{ .c = 'o', .string = "output", .flag = FLAG_OUTPUT },
		{ .c = 'j', .string = "johny", .flag = FLAG_JOHNY },
		{ .c = 'c', .string = "color", .flag = FLAG_COLOR }
	};

	return (parse(argc, argv, flags, arg_list));
}
