/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:48:08 by jjin              #+#    #+#             */
/*   Updated: 2022/02/12 11:17:02 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*tmp;

	tmp = dest;
	while (*tmp)
		tmp++;
	while (*src && nb--)
		*tmp++ = *src++;
	*tmp = '\0';
	return (dest);
}
