/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:48:45 by jjin              #+#    #+#             */
/*   Updated: 2022/02/24 09:33:07 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "do_op.h"

int	ft_opr(int n, char opr, int m)
{
	int		(*f[5])(int, int);
	int		ret;

	ret = 0;
	f[0] = &ft_add;
	f[1] = &ft_sub;
	f[2] = &ft_mul;
	f[3] = &ft_div;
	f[4] = &ft_mod;
	if (opr == '+')
		ret = f[0](n, m);
	else if (opr == '-')
		ret = f[1](n, m);
	else if (opr == '*')
		ret = f[2](n, m);
	else if (opr == '/')
		ret = f[3](n, m);
	else
		ret = f[4](n, m);
	return (ret);
}

void	do_op(char *a, char *o, char *b)
{
	int		n;
	int		m;

	n = ft_atoi(a);
	m = ft_atoi(b);
	if (!(*o == '+' || *o == '-' || *o == '/' || *o == '*' || *o == '%'))
		write(1, "0", 1);
	else if (o[1])
		write(1, "0", 1);
	else if (*o == '/' && m == 0)
		write(1, "Stop : division by zero", 23);
	else if (*o == '%' && m == 0)
		write(1, "Stop : modulo by zero", 21);
	else
		ft_putnbr(ft_opr(n, *o, m));
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	do_op(av[1], av[2], av[3]);
}
