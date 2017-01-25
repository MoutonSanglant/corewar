/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 23:20:52 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/25 18:36:02 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	short_flag(char *arg, int c)
{
	return (arg[1] != '-' && ft_strchr(&arg[1], c));
}

static int long_flag(char *arg, char *str)
{
	return (arg[1] == '-' && ft_strequ(&arg[2], str));
}

static int	parse_arg(char *arg, const t_option *options, t_flags *flags)
{
	t_option	opt;
	int			i;

	i = 0;
	while (i < OPTIONS_COUNT)
	{
		opt = options[i];
		if (arg[0] == '-' && (short_flag(arg, opt.c) || long_flag(arg, opt.s)))
		{
			*flags |= opt.f;
		}
		i++;
	}
	return (0);
}

static int	parse(int argc, char **argv, const t_option *options, t_flags *flags)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	*flags = FLAG_NONE;
	while (i < argc)
	{
		parse_arg(argv[i], options, flags);
		count++;
		i++;
	}
	return (count);
}

int			parse_arguments(int argc, char **argv, t_flags *flags)
{
	static const t_option	options[OPTIONS_COUNT] =
	{
		{ .c = 'd', .s = "dump", .f = FLAG_DUMP },
		{ .c = 'v', .s = "verbose", .f = FLAG_VERB },
		{ .c = 'n', .s = "number", .f = FLAG_NUMB },
		{ .c = 'c', .s = "ncurses", .f = FLAG_NCUR }
	};

	return (parse(argc, argv, options, flags));
}
