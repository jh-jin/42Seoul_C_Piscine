/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwshin <gwshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:16:49 by gwshin            #+#    #+#             */
/*   Updated: 2022/02/13 21:41:07 by yeogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

#include "rush01.h"

bool	fill_board(t_view *_view, t_board *_board, int y, int x)
{
	int	number;

	if (x == _board->width)
	{
		y += 1;
		x = 0;
	}
	if (y == _board->width)
		return (print_board(_board));
	number = 1;
	while (number <= _board->width)
	{
		_board->board[y][x] = number;
		if (check_board_valid(_view, _board, y, x)
			&& fill_board(_view, _board, y, x + 1))
			return (true);
		number++;
	}
	return (false);
}

bool	print_board(t_board *_board)
{
	int		index;
	int		jndex;
	char	c;

	index = 0;
	while (index < _board->width)
	{
		jndex = 0;
		while (jndex < _board->width)
		{
			c = _board->board[index][jndex] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			jndex++;
		}
		write(1, "\n", 1);
		index++;
	}
	return (true);
}

bool	check_board_valid(t_view *_view, t_board *_board, int y, int x)
{
	if (!check_unique(_board, y, x))
		return (false);
	if (x == _board->width - 1)
		if (!check_left_view(_view, _board, y, x)
			|| !check_right_view(_view, _board, y, x))
			return (false);
	if (y == _board->width - 1)
		if (!check_up_view(_view, _board, y, x)
			|| !check_down_view(_view, _board, y, x))
			return (false);
	return (true);
}
