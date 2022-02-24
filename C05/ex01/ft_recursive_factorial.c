/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:23:19 by jjin              #+#    #+#             */
/*   Updated: 2022/02/14 21:04:26 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	ans;

	if (nb < 0)
		return (0);
	ans = 1;
	if (nb <= 1)
		return (ans);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}
