/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:12:17 by jjin              #+#    #+#             */
/*   Updated: 2022/02/19 15:52:15 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (*str++)
		ret++;
	return (ret);
}

int	atoi_return(char *str, long long answer, long long sign, int len)
{
	if (sign == 1 && len > 19)
		return (-1);
	else if (sign == -1 && len > 19)
		return (0);
	while (*str >= '0' && *str <= '9')
		answer = answer * 10 + *str++ - '0';
	answer = sign * answer;
	if (sign == 1 && len == 19 && answer <= -1981284353)
		return (-1);
	if (sign == -1 && len == 19 && answer >= 1981284353)
		return (0);
	return ((int)answer);
}

int	ft_atoi(char *str)
{
	long long	sign;
	long long	answer;
	int			len;

	answer = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	len = ft_strlen(str);
	return (atoi_return(str, answer, sign, len));
}

int	check_valid_num(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char			*str;
	unsigned int	num;

	str = 0;
	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2 || argc == 3)
		str = argv[argc - 1];
	if (!check_valid_num(str))
		write(1, "Error\n", 6);
	num = ft_atoi(str);
	return (0);
}
