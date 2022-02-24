/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:44:07 by jjin              #+#    #+#             */
/*   Updated: 2022/02/13 20:11:57 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
int	is_invalid_base(char *base)
{
	char	*cp;
	char	*tmp;

	cp = base;
	if (!*cp || !*(cp + 1))
		return (1);
	while (*cp)
	{
		tmp = cp;
		while (*(++tmp))
			if (*cp == *tmp)
				return (1);
		if (*cp == '+' || *cp == '-'
			|| (*cp > 8 && *cp < 14) || *cp == 32)
			return (1);
		cp++;
	}
	return (0);
}

int	ft_put_base(char *str, char *base, unsigned int baselen, long long sign)
{
	long long	answer;
	char		*num;

	num = base;
	answer = 0;
	while (*str)
	{
		num = base;
		while (*num)
		{
			if (*str == *num)
			{
				answer = answer * baselen + (num - base);
				break ;
			}
			num++;
		}
		if (!*num)
			return ((int)(sign * answer));
		str++;
	}
	return ((int)(sign * answer));
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	baselen;
	long long		sign;

	sign = 1;
	if (is_invalid_base(base))
		return (0);
	baselen = 0;
	while (base[baselen])
		baselen++;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	return (ft_put_base(str, base, baselen, sign));
}
