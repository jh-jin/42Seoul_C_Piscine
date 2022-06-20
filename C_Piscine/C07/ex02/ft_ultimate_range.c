/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:31:48 by jjin              #+#    #+#             */
/*   Updated: 2022/02/21 21:22:38 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		*arr;
	int		*cp;
	int		ret;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	ret = max - min;
	arr = (int *)malloc(sizeof(int) * ret);
	*range = arr;
	if (!arr)
		return (-1);
	cp = arr;
	while (min < max)
		*cp++ = min++;
	return (ret);
}
