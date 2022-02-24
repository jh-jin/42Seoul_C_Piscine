/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwshin <gwshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:08:23 by yeogo             #+#    #+#             */
/*   Updated: 2022/02/13 21:46:48 by yeogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdbool.h>

typedef struct s_view
{
	int	*view;
	int	*view_up;
	int	*view_down;
	int	*view_left;
	int	*view_right;
}	t_view;

typedef struct s_board
{
	int	**board;
	int	width;
}	t_board;

int		get_view_length(char *input_line);
int		*make_view(char *input_line, int view_len);
void	parse_input(int *view, char *input_line);
int		**make_board(int width);
bool	initialize_struct(t_view *_view, t_board *_board, char *input_line);
int		free_board(int **board, int n);
void	initialize_board(int *board_line, int width);
bool	fill_board(t_view *_view, t_board *_board, int y, int x);
bool	print_board(t_board *_board);
bool	check_unique(t_board *_board, int y, int x);
bool	check_board_valid(t_view *_view, t_board *_board, int y, int x);
bool	check_left_view(t_view *_view, t_board *board, int y, int x);
bool	check_right_view(t_view *_view, t_board *board, int y, int x);
bool	check_up_view(t_view *_view, t_board *board, int y, int x);
bool	check_down_view(t_view *_view, t_board *board, int y, int x);
int		error_message(void);

#endif
