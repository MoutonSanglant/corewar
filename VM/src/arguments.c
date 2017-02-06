/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 23:20:52 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/06 17:28:23 by tdefresn         ###   ########.fr       */
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

	*flags &= ~FLAG_DUMP;
	*flags &= ~FLAG_NUMB;
	i = 0;
	while (i < OPTIONS_COUNT)
	{
		opt = options[i];
		if (short_flag(arg, opt.c) || long_flag(arg, opt.s))
			*flags |= opt.f;
		i++;
	}
}

static void	parse(int argc, char **argv, const t_option *options, t_flags *flags)
{
	char		*arg;
	int			i;

	i = 0;
	*flags = FLAG_NONE;
	while (i < argc)
	{
		arg = argv[i];
		if (*flags & FLAG_DUMP)
		{
			if (!ft_isdigit(arg[0]))
				error(ERRNO_USAGE, NULL);
			g_corewar.dump_cycle = ft_atoi(arg);
			*flags &= ~FLAG_DUMP;
		}
		else if (*flags & FLAG_NUMB)
		{
			if (!ft_isdigit(arg[0]))
				error(ERRNO_USAGE, NULL);
			read_champion(argv[i + 1], ft_atoi(argv[i]));
			*flags &= ~FLAG_NUMB;
			i++;
		}
		else if (arg[0] != '-')
			read_champion(arg, -1);
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

	g_corewar.dump_cycle = -1;
	parse(argc, argv, options, flags);
}
