/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:49:50 by jjin              #+#    #+#             */
/*   Updated: 2022/02/10 15:55:15 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_DcmToHex(unsigned char c)
{
	if (c >= 10)
		c = 'a' + c % 10;
	else
		c = '0' + c % 10;
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			c = str[i];
			write(1, "\\", 1);
			ft_DcmToHex(c / 16);
			ft_DcmToHex(c % 16);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
