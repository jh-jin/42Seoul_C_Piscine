/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:01:04 by jjin              #+#    #+#             */
/*   Updated: 2022/02/07 14:46:34 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	first;
	int	min;
	int	i;
	int	tmp;

	first = 0;
	while (first < size - 1)
	{
		i = first + 1;
		min = i;
		while (i < size)
		{
			if (tab[i] < tab[min])
				min = i;
			i++;
		}
		if (tab[first] > tab[min])
		{
			tmp = tab[first];
			tab[first] = tab[min];
			tab[min] = tmp;
		}
		first++;
	}
}
