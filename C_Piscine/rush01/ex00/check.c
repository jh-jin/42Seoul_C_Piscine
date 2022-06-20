/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwshin <gwshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:18:03 by gwshin            #+#    #+#             */
/*   Updated: 2022/02/13 18:25:45 by gwshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "rush01.h"

bool	check_unique(t_board *_board, int y, int x)
{
	int	index;

	index = 0;
	while (index < x)
	{
		if (_board->board[y][index] == _board->board[y][x])
			return (false);
		index++;
	}
	index = 0;
	while (index < y)
	{
		if (_board->board[index][x] == _board->board[y][x])
			return (false);
		index++;
	}
	return (true);
}

bool	check_left_view(t_view *_view, t_board *_board, int y, int x)
{
	int	max;
	int	height;
	int	index;

	max = 0;
	height = 0;
	index = 0;
	while (index <= x)
	{
		if (max < _board->board[y][index])
		{
			max = _board->board[y][index];
			height++;
		}
		index++;
	}
	if (height != *(_view->view_left + y))
		return (false);
	return (true);
}

bool	check_right_view(t_view *_view, t_board *_board, int y, int x)
{
	int	max;
	int	index;
	int	height;

	max = 0;
	height = 0;
	index = x;
	while (index >= 0)
	{
		if (max < _board->board[y][index])
		{
			max = _board->board[y][index];
			height++;
		}
		index--;
	}
	if (height != *(_view->view_right + y))
		return (false);
	return (true);
}

bool	check_up_view(t_view *_view, t_board *_board, int y, int x)
{
	int	max;
	int	index;
	int	height;

	max = 0;
	height = 0;
	index = 0;
	while (index <= y)
	{
		if (max < _board->board[index][x])
		{
			max = _board->board[index][x];
			height++;
		}
		index++;
	}
	if (height != *(_view->view_up + x))
		return (false);
	return (true);
}

bool	check_down_view(t_view *_view, t_board *_board, int y, int x)
{
	int	max;
	int	index;
	int	height;

	max = 0;
	height = 0;
	index = y;
	while (index >= 0)
	{
		if (max < _board->board[index][x])
		{
			max = _board->board[index][x];
			height++;
		}
		index--;
	}
	if (height != *(_view->view_down + x))
		return (false);
	return (true);
}
