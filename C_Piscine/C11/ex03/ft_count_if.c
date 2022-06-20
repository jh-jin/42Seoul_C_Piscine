/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:54:12 by jjin              #+#    #+#             */
/*   Updated: 2022/02/24 09:40:57 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int		cntnotz;
	int		i;

	cntnotz = 0;
	i = -1;
	while (++i < length)
		if (f(tab[i]) != 0)
			cntnotz++;
	return (cntnotz);
}
