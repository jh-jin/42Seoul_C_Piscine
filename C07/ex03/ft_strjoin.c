/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:20:28 by jjin              #+#    #+#             */
/*   Updated: 2022/02/24 16:21:25 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen2(char *str)
{
	int		len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	ft_totallen(int size, char **strs, char *sep)
{
	int		len;
	int		i;

	if (size == 0)
		return (0);
	len = 0;
	len += ft_strlen2(strs[0]);
	i = 1;
	while (i < size)
		len = len + ft_strlen2(sep) + ft_strlen2(strs[i++]);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		iret;
	int		i;
	int		j;

	ret = (char *)malloc(ft_totallen(size, strs, sep) + 1);
	ret[ft_totallen(size, strs, sep)] = '\0';
	if (size == 0)
		return (ret);
	iret = 0;
	j = 0;
	while (strs[0][j])
		ret[iret++] = strs[0][j++];
	i = 1;
	while (i < size)
	{
		j = 0;
		while (sep[j])
			ret[iret++] = sep[j++];
		j = 0;
		while (strs[i][j])
			ret[iret++] = strs[i][j++];
		i++;
	}
	return (ret);
}
