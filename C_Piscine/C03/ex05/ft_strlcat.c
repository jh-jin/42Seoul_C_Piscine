/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:26:09 by jjin              #+#    #+#             */
/*   Updated: 2022/02/12 16:46:17 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	lenDest;
	unsigned int	lenSrc;

	lenDest = 0;
	while (*dest)
	{
		lenDest++;
		dest++;
	}
	lenSrc = 0;
	while (*src && lenDest + lenSrc + 1 < size)
	{
		*dest++ = *src++;
		lenSrc++;
	}
	while (*src++ != '\0')
		lenSrc++;
	*dest = '\0';
	if (size <= lenDest)
		return (size + lenSrc);
	return (lenDest + lenSrc);
}
