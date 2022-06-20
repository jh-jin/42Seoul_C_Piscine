/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:59:14 by hyejlee           #+#    #+#             */
/*   Updated: 2022/02/06 15:49:27 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_mid_line(int x, char mid)
{
	int	xi;

	xi = 1;
	while (xi <= x)
	{
		if (xi == 1 || xi == x)
			ft_putchar(mid);
		else
			ft_putchar(' ');
		xi++;
	}
	ft_putchar('\n');
}

void	print_first_last_line(int x, char first, char mid, char last)
{
	int	xi;

	xi = 1;
	while (xi <= x)
	{
		if (xi == 1)
			ft_putchar(first);
		else if (xi == x)
			ft_putchar(last);
		else
			ft_putchar(mid);
		xi++;
	}
	ft_putchar('\n');
}

void	ft_print(int x, int y)
{
	char	ch[3];
	int		yi;

	ch[0] = 'A';
	ch[1] = 'B';
	ch[2] = 'C';
	yi = 1;
	while (yi <= y)
	{
		if (yi == 1)
			print_first_last_line(x, ch[0], ch[1], ch[2]);
		else if (yi == y)
			print_first_last_line(x, ch[0], ch[1], ch[2]);
		else
			print_mid_line(x, ch[1]);
		yi++;
	}
}

void	rush(int x, int y)
{
	if (x < 1 || y < 1)
		return ;
	ft_print(x, y);
}
