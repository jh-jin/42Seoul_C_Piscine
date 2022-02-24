/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:28:21 by jjin              #+#    #+#             */
/*   Updated: 2022/02/21 15:55:36 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *src, char *dest)
{
	char	*ret;

	ret = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (ret);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	int		len;

	len = 0;
	while (src[len])
		len++;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ret = ft_strcpy(src, ret);
	return (ret);
}
