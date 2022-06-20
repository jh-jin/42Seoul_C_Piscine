/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:07:00 by jjin              #+#    #+#             */
/*   Updated: 2022/02/08 21:07:01 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int num1, int num2)
{
	char	tmp;

	tmp = '0' + num1 / 10;
	write(1, &tmp, 1);
	tmp = '0' + num1 % 10;
	write(1, &tmp, 1);
	write(1, " ", 1);
	tmp = '0' + num2 / 10;
	write(1, &tmp, 1);
	tmp = '0' + num2 % 10;
	write(1, &tmp, 1);
	if (num1 != 98 || num2 != 99)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			ft_write(num1, num2);
			num2++;
		}
		num1++;
	}
}
