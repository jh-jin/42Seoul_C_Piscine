#include <unistd.h>
#include "ft_stock_str.h"

void	ft_write_int(int num)
{
	char	tmp;
	int		quotient;
	int		remain;

	quotient = num / 10;
	remain = num % 10;
	if (quotient != 0)
		ft_write_int(quotient);
	tmp = '0' + remain;
	write(1, &tmp, 1);
}

void	ft_write_str(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;

	i = -1;
	while (par[++i].str)
	{
		ft_write_str(par[i].str);
		ft_write_int(par[i].size);
		write(1, "\n", 1);
		ft_write_str(par[i].copy);
	}
}
