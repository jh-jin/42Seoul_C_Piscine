/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:18:16 by jjin              #+#    #+#             */
/*   Updated: 2022/02/20 14:59:45 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	abs_q(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

int	is_promise(int arr[10], int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (y == arr[i])
			return (0);
		else if (abs_q(y - arr[i]) == abs_q(x - i))
			return (0);
		i++;
	}
	return (1);
}

void	putchar_q(char c)
{
	write(1, &c, 1);
}

void	putqueen_recur(int arr[10], int *cnt, int x)
{
	int	y;
	int	i;

	if (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			if (is_promise(arr, x, y))
			{
				arr[x] = y;
				putqueen_recur(arr, cnt, x + 1);
			}
			y++;
		}
	}
	else
	{
		*cnt = *cnt + 1;
		i = 0;
		while (i < 10)
			putchar_q('0' + arr[i++]);
		putchar_q('\n');
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	i;
	int	cnt;

	i = 0;
	while (i < 10)
		arr[i++] = -1;
	cnt = 0;
	putqueen_recur(arr, &cnt, 0);
	return (cnt);
}
