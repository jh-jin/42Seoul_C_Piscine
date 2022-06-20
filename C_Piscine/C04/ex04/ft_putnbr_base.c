/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:43:55 by jjin              #+#    #+#             */
/*   Updated: 2022/02/13 21:25:36 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_invalid_base(char *base)
{
	char	*cp;

	if (!*base || !*(base + 1))
		return (1);
	while (*base)
	{
		cp = base;
		cp++;
		while (*cp)
		{
			if (*base == *cp)
				return (1);
			cp++;
		}
		if (*base == '+' || *base == '-')
			return (1);
		base++;
	}
	return (0);
}

void	ft_write_base(long long num, long long baselen, char *base)
{
	char		tmp;
	long long	quotient;
	long long	remain;

	quotient = num / baselen;
	remain = num % baselen;
	if (quotient != 0)
		ft_write_base(quotient, baselen, base);
	tmp = *(base + remain);
	write(1, &tmp, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	num;
	char		*cp;
	long long	baselen;

	num = (long long) nbr;
	cp = base;
	baselen = 0;
	while (*cp++)
		baselen++;
	if (is_invalid_base(base))
		return ;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	ft_write_base(num, baselen, base);
}
