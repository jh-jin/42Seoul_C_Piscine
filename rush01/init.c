/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwshin <gwshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:18:38 by gwshin            #+#    #+#             */
/*   Updated: 2022/02/13 21:50:08 by yeogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "rush01.h"

bool	initialize_struct(t_view *_view, t_board *_board, char *input_line)
{
	int	view_len;

	view_len = get_view_length(input_line);
	if (view_len == -1)
		return (false);
	_board->width = view_len / 4;
	_view->view = make_view(input_line, view_len);
	_view->view_up = _view->view;
	_view->view_down = _view->view + _board->width * 1;
	_view->view_left = _view->view + _board->width * 2;
	_view->view_right = _view->view + _board->width * 3;
	_board->board = make_board(view_len);
	if (_board->board == NULL)
	{
		free(_view->view);
		return (false);
	}
	return (true);
}

int	get_view_length(char *input_line)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (input_line[index])
	{
		if (index % 2 == 0)
		{
			if ('1' <= input_line[index] && input_line[index] <= '9')
				count++;
			else
				return (-1);
		}
		else
		{
			if (input_line[index] != ' ')
				return (-1);
		}
		index++;
	}
	if (count == 0 || count % 4 != 0 || count > 36 || (index + 1) % 4 != 0)
		return (-1);
	return (count);
}

int	*make_view(char *input_line, int view_len)
{
	int	*view;

	view = (int *) malloc(sizeof(int) * view_len);
	if (view == NULL)
	{
		error_message();
		return (NULL);
	}
	parse_input(view, input_line);
	return (view);
}

int	**make_board(int width)
{
	int	**board;
	int	index;

	index = 0;
	board = (int **) malloc(sizeof(int *) * width);
	if (board == NULL)
	{
		error_message();
		return (NULL);
	}
	while (index < width)
	{
		board[index] = (int *) malloc(sizeof(int) * width);
		if (board[index] == NULL)
		{
			free_board(board, index);
			error_message();
			return (NULL);
		}
		initialize_board(board[index], width);
		index++;
	}
	return (board);
}

void	initialize_board(int *board_line, int width)
{
	int	index;

	index = 0;
	while (index < width)
	{
		board_line[index] = 0;
		index++;
	}
}
