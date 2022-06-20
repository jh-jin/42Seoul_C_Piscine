#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen_s(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_putwd_s(char *str)
{
	int		len;
	char	*ret;
	int		i;

	len = ft_strlen_s(str);
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ret;
	int			i;

	ret = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		ret[i].size = ft_strlen_s(av[i]);
		ret[i].str = av[i];
		ret[i].copy = ft_putwd_s(av[i]);
		if (!ret[i].copy)
			return (NULL);
		i++;
	}
	ret[i].str = 0;
	ret[i].copy = 0;
	return (ret);
}
