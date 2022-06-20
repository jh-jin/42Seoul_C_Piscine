/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwshin <gwshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:08:18 by yeogo             #+#    #+#             */
/*   Updated: 2022/02/13 21:39:42 by yeogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "rush01.h"

int	main(int argc, char **argv)
{
	t_view	_view;
	t_board	_board;
	bool	succeed;

	if (argc != 2)
		return (error_message());
	if (!initialize_struct(&_view, &_board, argv[1]))
		return (error_message());
	succeed = fill_board(&_view, &_board, 0, 0);
	free(_view.view);
	free(_board.board);
	free_board(_board.board, _board.width);
	if (!succeed)
		return (error_message());
	return (0);
}
