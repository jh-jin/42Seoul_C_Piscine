/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:43:41 by jjin              #+#    #+#             */
/*   Updated: 2022/02/24 09:33:04 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int			sign;
	long long	answer;

	answer = 0;
	sign = 1;
	while ((*str > 7 && *str < 14) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
		answer = answer * 10 + *str++ - '0';
	return ((int)(sign * answer));
}
