#include "asm.h"

int		check_or(char *arg, t_label *u)
{
	if (!check_dir(arg, u) && !check_ind(arg, u) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_dir(arg, u) && !check_ind(arg, u) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}

int		check_xor(char *arg, t_label *u)
{
	if (!check_dir(arg, u) && !check_ind(arg, u) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_dir(arg, u) && !check_ind(arg, u) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}

int		check_zjmp(char *arg, t_label *u)
{
	if (!check_dir(arg, u))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}

int		check_ldi(char *arg, t_label *u)
{
	if (!check_dir(arg, u) && !check_ind(arg, u) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_dir(arg, u) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}

int		check_sti(char *arg, t_label *u)
{
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_dir(arg, u) && !check_ind(arg, u) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_dir(arg, u) && !check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}
