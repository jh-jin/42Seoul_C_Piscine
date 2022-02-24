/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:54:58 by jjin              #+#    #+#             */
/*   Updated: 2022/02/12 14:41:18 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	lensrc;

	i = 0;
	lensrc = 0;
	while (src[lensrc] != '\0')
		lensrc++;
	if (size == 0)
		return (lensrc);
	while (i + 1 < size && i < lensrc)
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
		dest[i] = '\0';
	return (lensrc);
}
