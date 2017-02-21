/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 23:20:52 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/21 22:07:26 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	set_dump(char *arg, t_flags *flags)
{
	if (!ft_isdigit(arg[0]))
		error(ERRNO_USAGE, NULL);
	g_corewar.dump_cycle = ft_atoi(arg);
	*flags &= ~FLAG_DUMP;
}

static void	set_champ_num(char **argv, int n, char *arg, t_flags *flags)
{
	if (!ft_isdigit(arg[0]))
		error(ERRNO_USAGE, NULL);
	read_champion(argv[n + 1], ft_atoi(argv[n]));
	*flags &= ~FLAG_NUMB;
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
		if ((arg[1] != '-' && ft_strchr(&arg[1], opt.c))
				|| (arg[1] == '-' && ft_strequ(&arg[2], opt.s)))
			*flags |= opt.f;
		i++;
	}
}

static void	parse(int argc, char **argv, const t_option *opt, t_flags *flags)
{
	char		*arg;
	int			i;

	i = 0;
	*flags = FLAG_NONE;
	while (i < argc)
	{
		arg = argv[i];
		if (*flags & FLAG_DUMP)
			set_dump(arg, flags);
		else if (*flags & FLAG_NUMB)
			set_champ_num(argv, i++, arg, flags);
		else if (arg[0] != '-')
			read_champion(arg, -1);
		else
			match_option(arg, opt, flags);
		i++;
	}
}

void		parse_arguments(int argc, char **argv, t_flags *flags)
{
	static const t_option	options[OPTIONS_COUNT] = {
		{ .c = 'd', .s = "dump", .f = FLAG_DUMP },
		{ .c = 'v', .s = "verbose", .f = FLAG_VERB },
		{ .c = 'n', .s = "number", .f = FLAG_NUMB },
		{ .c = 'c', .s = "ncurses", .f = FLAG_NCUR }
	};

	parse(argc, argv, options, flags);
	if (*flags & FLAG_NCUR)
		g_corewar.dump_cycle = -1;
}
