#include <libft.h>
#include <libftprintf.h>

#include "corewar.h"

#define TYPE int
#define REG_COUNT 5

static void		print_value(char *val, size_t size)
{
	size_t		i;

	i = 0;
	ft_printf("value: ");
	while (i < size)
	{
		ft_printf("%x ", val[i]);
		i++;
	}
	ft_putchar('\n');
}

static void		print_register(t_registry reg)
{
	size_t		i;

	i = 0;
	ft_printf("registry: ");
	while (i < REG_SIZE)
	{
		ft_printf("%x ", reg[i]);
		i++;
	}
	ft_putchar('\n');
}

int main (void)
{
	t_registry	reg[REG_COUNT];
	TYPE		i;

	i = 2101;
	ft_bzero(&reg, sizeof(t_registry) * REG_COUNT);
	set_reg(reg[0], (char *)&i, sizeof(TYPE));
	print_value((char *)&i, sizeof(TYPE));
	print_register(reg[0]);

	return (0);
}
