/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:21:14 by jjin              #+#    #+#             */
/*   Updated: 2022/02/24 12:59:03 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * length);
	i = -1;
	while (++i < length)
		ret[i] = f(tab[i]);
	return (ret);
}
