/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:46:48 by jjin              #+#    #+#             */
/*   Updated: 2022/02/13 12:24:41 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*cp;
	char	*s1;
	char	*s2;

	cp = str;
	if (*to_find == 0)
		return (str);
	while (*cp)
	{
		s1 = cp;
		s2 = to_find;
		while (*s1 && *s2 && (*s1 == *s2))
			s1++, s2++;
		if (*s2 == 0)
			return (cp);
		cp++;
	}
	return (0);
}
