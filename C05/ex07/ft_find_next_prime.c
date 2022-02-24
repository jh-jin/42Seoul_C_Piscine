/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:42:17 by jjin              #+#    #+#             */
/*   Updated: 2022/02/20 14:05:48 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime_n(int nb)
{
	int	i;

	if (nb == 2)
		return (1);
	i = 2;
	while (i <= nb / i)
		if (nb % i++ == 0)
			return (0);
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	answer;

	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
		answer = nb + 1;
	else
		answer = nb;
	while (1)
	{
		if (ft_is_prime_n(answer))
			return (answer);
		answer += 2;
	}
}
