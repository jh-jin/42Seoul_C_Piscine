/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:57:01 by jjin              #+#    #+#             */
/*   Updated: 2022/02/24 15:58:09 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	ft_digitlen(long long num, int baselen)
{
	int		digitlen;

	digitlen = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		digitlen++;
		num /= baselen;
	}
	return (digitlen);
}

void	ft_putbase_to(char *cp, long long num, char *base, int idx)
{
	char	c;
	int		quotient;
	int		remain;
	int		baselen;
	int		digitlen;

	quotient = 0;
	remain = 0;
	baselen = 0;
	digitlen = 0;
	baselen = ft_strlen(base);
	digitlen = ft_digitlen(num, baselen);
	quotient = num / baselen;
	remain = num % baselen;
	if (quotient != 0)
		ft_putbase_to(cp, quotient, base, idx);
	c = *(base + remain);
	cp[digitlen - 1] = c;
}

char	*ft_itoa_base(int nbr, char *base)
{
	long long	num;
	int			baselen;
	int			signlen;
	char		*ret;
	char		*cp;

	num = (long long) nbr;
	signlen = 0;
	if (num < 0)
		signlen = 1;
	baselen = 0;
	baselen = ft_strlen(base);
	ret = (char *)malloc(signlen + ft_digitlen(num, baselen) + 1);
	ret[signlen + ft_digitlen(num, baselen)] = '\0';
	if (!ret)
		return (NULL);
	cp = ret;
	if (signlen)
	{
		*cp++ = '-';
		num *= -1;
	}
	ft_putbase_to(cp, num, base, 0);
	return (ret);
}
