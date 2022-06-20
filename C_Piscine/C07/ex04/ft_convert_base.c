/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:56:53 by jjin              #+#    #+#             */
/*   Updated: 2022/02/24 16:03:23 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		is_invalid_base(char *base);
int		ft_putbase_from(char *str, char *base, int baselen, long long sign);
int		is_inbase(char c, char *base_from);
int		ft_strlen(char *str);
int		ft_digitlen(long long num, int baselen);
void	ft_putbase_to(char *cp, long long num, char *base, int idx);
char	*ft_itoa_base(int nbr, char *base);

int	is_inbase(char c, char *base_from)
{
	while (*base_from)
		if (c == *base_from++)
			return (1);
	return (0);
}

char	*ft_convert_base(char *str, char *base_from, char *base_to)
{
	int				num;
	unsigned int	baselen;
	long long		sign;

	num = 0;
	if (is_invalid_base(base_from) || is_invalid_base(base_to))
		return (0);
	sign = 1;
	baselen = 0;
	while (base_from[baselen])
		baselen++;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	if (!is_inbase(*str, base_from))
		return (0);
	num = ft_putbase_from(str, base_from, baselen, sign);
	return (ft_itoa_base(num, base_to));
}

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

int	ft_putbase_from(char *str, char *base, int baselen, long long sign)
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
