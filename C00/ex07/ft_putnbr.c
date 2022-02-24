/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:07:15 by jjin              #+#    #+#             */
/*   Updated: 2022/02/09 10:52:50 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(long long num)
{
	char	tmp;
	int		quotient;
	int		remain;

	quotient = num / 10;
	remain = num % 10;
	if (quotient != 0)
		ft_write(quotient);
	tmp = '0' + remain;
	write(1, &tmp, 1);
}

void	ft_putnbr(int nb)
{
	long long int	num;

	num = (long long) nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		num = num * -1;
	}
	ft_write(num);
}
