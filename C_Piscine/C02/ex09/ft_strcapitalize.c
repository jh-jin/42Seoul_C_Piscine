/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:47:15 by jjin              #+#    #+#             */
/*   Updated: 2022/02/08 20:18:21 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_type(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	else if (c >= '0' && c <= '9')
		return (3);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	isFirst;

	i = 0;
	isFirst = 1;
	while (str[i] != '\0')
	{
		if (ft_type(str[i]) == 0)
			isFirst = 1;
		else
		{
			if (!isFirst && ft_type(str[i]) == 2)
				str[i] += 32;
			else if (isFirst && ft_type(str[i]) == 1)
				str[i] -= 32;
			isFirst = 0;
		}
		i++;
	}
	return (str);
}
