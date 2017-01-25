/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 23:20:52 by tdefresn          #+#    #+#             */
/*   Updated: 2017/01/26 00:05:51 by tdefresn         ###   ########.fr       */
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

static void	match_option(char *arg, const t_option *options, t_flags *flags)
{
	t_option	opt;
	int			i;

	i = 0;
	while (i < OPTIONS_COUNT)
	{
		opt = options[i];
		if (short_flag(arg, opt.c) || long_flag(arg, opt.s))
		{
			*flags |= opt.f;
		}
		i++;
	}
}

static void	parse(int argc, char **argv, const t_option *options, t_flags *flags)
{
	static int	champion_number = -1;
	char		*arg;
	int			i;

	i = 0;
	*flags = FLAG_NONE;
	while (i < argc)
	{
		arg = argv[i];
		if (arg[0] != '-')
		{
			if (*flags & FLAG_NUMB)
			{
				champion_number = ft_atoi(arg);
				arg++;
				i++;
			}
			read_champion(arg, champion_number);
			champion_number = -1;
		}
		else
			match_option(arg, options, flags);
		i++;
	}
}

void		parse_arguments(int argc, char **argv, t_flags *flags)
{
	static const t_option	options[OPTIONS_COUNT] =
	{
		{ .c = 'd', .s = "dump", .f = FLAG_DUMP },
		{ .c = 'v', .s = "verbose", .f = FLAG_VERB },
		{ .c = 'n', .s = "number", .f = FLAG_NUMB },
		{ .c = 'c', .s = "ncurses", .f = FLAG_NCUR }
	};

	parse(argc, argv, options, flags);
}
