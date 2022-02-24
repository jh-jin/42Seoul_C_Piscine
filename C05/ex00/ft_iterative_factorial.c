/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:25:25 by jjin              #+#    #+#             */
/*   Updated: 2022/02/14 20:27:47 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ans;

	if (nb < 0)
		return (0);
	ans = 1;
	while (nb)
		ans *= nb--;
	return (ans);
}
