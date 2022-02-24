/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:43:16 by jjin              #+#    #+#             */
/*   Updated: 2022/02/13 12:49:37 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlength(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlength(str));
}
