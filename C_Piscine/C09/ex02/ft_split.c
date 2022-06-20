/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:30:05 by jjin              #+#    #+#             */
/*   Updated: 2022/02/23 11:30:23 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_deli(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

int	ft_wdcnt(char *str, char *charset)
{
	int		isfirst;
	int		wdcnt;

	isfirst = 1;
	wdcnt = 0;
	while (*str)
	{
		if (ft_is_deli(*str, charset))
			isfirst = 1;
		else if (!ft_is_deli(*str, charset) && isfirst)
			wdcnt++, isfirst = 0;
		str++;
	}
	return (wdcnt);
}

int	ft_charcnt(char *str, char *charset)
{
	int	charcnt;

	charcnt = 0;
	while (*str && !ft_is_deli(*str, charset))
		charcnt++, str++;
	return (charcnt);
}

char	*ft_put_wd(char *str, char *charset)
{
	char	*wd;
	int		charcnt;
	char	*cp;

	charcnt = ft_charcnt(str, charset);
	wd = (char *)malloc(sizeof(char) * (charcnt + 1));
	cp = wd;
	while (charcnt--)
		*wd++ = *str++;
	*wd = '\0';
	return (cp);
}

char	**ft_split(char *str, char *charset)
{
	int		wdcnt;
	char	**ret;
	char	**cp;

	wdcnt = ft_wdcnt(str, charset);
	ret = (char **)malloc(sizeof(char *) * (wdcnt + 1));
	cp = ret;
	if (!ret)
		return (0);
	while (*str)
	{
		while (ft_is_deli(*str, charset))
			str++;
		if (*str)
			*ret++ = ft_put_wd(str, charset);
		while (*str && !ft_is_deli(*str, charset))
			str++;
	}
	*ret = 0;
	return (cp);
}
