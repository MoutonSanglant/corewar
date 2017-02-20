#include "asm.h"
#include "get_next_line.h"

/*
static char		*tab[17] =
{
	{ "live" },
	{ "ld" },
	{ "st" },
	{ "add" },
	{ "sub" },
	{ "and" },
	{ "or" },
	{ "xor" },
	{ "zjmp" },
	{ "ldi" },
	{ "sti" },
	{ "fork" },
	{ "lld" },
	{ "lldi" },
	{ "lfork" },
	{ "aff" },
	{ NULL }
}; PROPCH.
*/
static t_op_check	op_list[17] =
{
	{ "live", &check_live },
	{ "ld", &check_ld },
	{ "st", &check_st },
	{ "add", &check_add },
	{ "sub", &check_sub },
	{ "and", &check_and },
	{ "or", &check_or },
	{ "xor", &check_xor },
	{ "zjmp", &check_zjmp },
	{ "ldi", &check_ldi },
	{ "sti", &check_sti },
	{ "fork", &check_fork },
	{ "lld", &check_lld },
	{ "lldi", &check_lldi },
	{ "lfork", &check_lfork },
	{ "aff", &check_aff },
	{ NULL, NULL },
};

static int	check_name(char *line, int *name)
{
	char	*s;

	s = ft_strtrim(line);
	if (s[0] != '"' || s[ft_strlen(s) - 1] != '"')
	{
		ft_strdel(&s);
		return (0);
	}
	(*name)++;
	ft_strdel(&s);
	return (1);
}

static int	check_comment(char *line, int *comment)
{
	char	*s;

	s = ft_strtrim(line);
	if (s[0] != '"' || s[ft_strlen(s) - 1] != '"')
	{
		ft_strdel(&s);
		return (0);
	}
	(*comment)++;
	ft_strdel(&s);
	return (1);
}

static int	check_args(char *line, t_label *u)
{
	int i;
	char **tab;

	i = 0;
	tab = split_line(line);
	if (!tab)
		return (0);
	while (op_list[i].name)
	{
		if (!ft_strcmp(tab[0], op_list[i].name))
		{
			i = op_list[i].fn(tab[1], u);
			break ;
		}
		i++;
	}
	ft_strdel(&(tab[0]));
	ft_strdel(&(tab[1]));
	free(tab);
	return (i);
}

static int	check_opcode(char *line, int *opcode, t_label *u)
{
	char	*s;
	size_t	i;

	s = ft_strtrim(line);
	i = 0;
	while (s[i])
	{
		if (!ft_isalpha(s[i]))
			break ;
		i++;
	}
	while (ft_isspace(s[i]))
		i++;
	if (!check_args(line, u))
		return (0);
	ft_strdel(&s);
	(*opcode)++;
	return (1);
}

static char	*save_label(char *line, t_label *d)
{
	size_t	i;
	t_label	*new;

	i = 0;
	new = init_label();
	while (line[i] != LABEL_CHAR)
		i++;
	new->label = ft_strsub(line, 0, i);
//	new->pos ?
	while (d->next)
		d = d->next;
	d->next = new;
	if (line[i + 1])
	{
		ft_printf("YO");
		return (&(line[i + 1]));
	}
	return (NULL);
}

static int	type_of_line(char *line)
{
	int i;

	i = 0;
	if (!ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))) // name return 1
		return (1);
	if (!ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING))) // comment return 2
		return (2);
	if (!ft_strncmp(line, "live", 4) && ft_isspace(line[4])) // opcode return 3
		return (3);
	if (!ft_strncmp(line, "ld", 2) && ft_isspace(line[2]))
		return (3);
	if (!ft_strncmp(line, "st", 2) && ft_isspace(line[2]))
		return (3);
	if (!ft_strncmp(line, "add", 3) && ft_isspace(line[3]))
		return (3);
	if (!ft_strncmp(line, "sub", 3) && ft_isspace(line[3]))
		return (3);
	if (!ft_strncmp(line, "and", 3) && ft_isspace(line[3]))
		return (3);
	if (!ft_strncmp(line, "or", 2) && ft_isspace(line[2]))
		return (3);
	if (!ft_strncmp(line, "xor", 3) && ft_isspace(line[3]))
		return (3);
	if (!ft_strncmp(line, "zjmp", 4) && ft_isspace(line[4]))
		return (3);
	if (!ft_strncmp(line, "ldi", 3) && ft_isspace(line[3]))
		return (3);
	if (!ft_strncmp(line, "sti", 3) && ft_isspace(line[3]))
		return (3);
	if (!ft_strncmp(line, "fork", 4) && ft_isspace(line[4]))
		return (3);
	if (!ft_strncmp(line, "lld", 3) && ft_isspace(line[3]))
		return (3);
	if (!ft_strncmp(line, "lldi", 4) && ft_isspace(line[4]))
		return (3);
	if (!ft_strncmp(line, "lfork", 5) && ft_isspace(line[5]))
		return (3);
	if (!ft_strncmp(line, "aff", 3) && ft_isspace(line[3]))
		return (3);
	while (line[i])
	{
		if (line[i] == LABEL_CHAR)
			return (4); // 4 label
		if (!ft_strchr(LABEL_CHARS, line[i]))
			return (0);
		i++;
	}
	return (0);
}

static int	check_invalid_line(char *line, int type, int *name, int *comment, int *opcode, t_label *d, t_label *u)
{
	if (type == 4)
	{
		line = save_label(line, d);
		if (!line)
			return (1);
		type = type_of_line(line);
	}
	if (type == 1)
		return (check_name(line + ft_strlen(NAME_CMD_STRING), name));
	if (type == 2)
		return (check_comment(line + ft_strlen(COMMENT_CMD_STRING), comment));
	if (!type || *name < 1 || *comment < 1) // erreur ligne correspond a rien, ou opcode/label avant name/comment
		return (0);
	if (type == 3)
		return (check_opcode(line, opcode, u));
	return (1);
}

static int	check_name_length(char *s)
{
	s += ft_strlen(NAME_CMD_STRING);
	while (ft_isspace(*s))
		s++;
	if (ft_strlen(s) - 2 > PROG_NAME_LENGTH)
		return (0);
	return (1);
}

static int	check_comment_length(char *s)
{
	s += ft_strlen(COMMENT_CMD_STRING);
	while (ft_isspace(*s))
		s++;
	if (ft_strlen(s) - 2 > COMMENT_LENGTH)
		return (0);
	return (1);
}

void		check_cmd_length(int fd)
{
	char	*line;
	char	*s;
	int		ret;

	while ((ret = get_next_line(fd, &line)))
	{
		s = ft_strtrim(line);
		if (ft_strcmp(s, ""))
		{
			if (type_of_line(s) == 1 && !check_name_length(s))
				exit(name_error());
			if (type_of_line(s) == 2 && !check_comment_length(s))
				exit(comment_error());
		}
		ft_strdel(&s);
		ft_strdel(&line);
	}
	lseek(fd, 0, SEEK_SET);
}

int			check_invalid_file(int fd, t_label *d, t_label *u)
{
	char	*line;
	char	*s;
	int		ret;
	int		name;
	int		comment;
	int		opcode;

	name = 0;
	comment = 0;
	opcode = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		s = ft_strtrim(line);
		if (s[0] != COMMENT_CHAR && ft_strcmp(s, "")) // on evite comm et ligne vide
		{
			if (!check_invalid_line(s, type_of_line(s), &name, &comment, &opcode, d, u))
			{
				ft_strdel(&line);
				ft_strdel(&s);
				return (0);
			}
		}
		ft_strdel(&line);
		ft_strdel(&s);
	}
	if (ret == -1)
		exit(ERROR_READ_SRC);
	if (name != 1 || comment != 1 || opcode < 1)
		return (0);
	lseek(fd, 0, SEEK_SET);
	return (1);
}
