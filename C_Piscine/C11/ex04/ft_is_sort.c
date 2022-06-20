/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:00:11 by jjin              #+#    #+#             */
/*   Updated: 2022/02/24 13:50:55 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	is_asc(int *tab, int length, int(*f)(int, int))
{
	int		i;

	i = 1;
	while (++i < length)
		if (f(tab[i - 1], tab[i]) > 0)
			return (0);
	return (1);
}

int	is_dec(int *tab, int length, int(*f)(int, int))
{
	int		i;

	i = 1;
	while (++i < length)
		if (f(tab[i - 1], tab[i]) < 0)
			return (0);
	return (1);
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	if (length == 0 || length == 1)
		return (1);
	return (is_asc(tab, length, f) || is_dec(tab, length, f));
}
