/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:08:29 by jjin              #+#    #+#             */
/*   Updated: 2022/02/24 13:24:04 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_cp(char	**t1, char **t2)
{
	char	*tmp;

	tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int		i;
	int		j;

	if (!tab[0])
		return ;
	i = -1;
	while (tab[++i])
	{
		j = 0;
		while (tab[++j])
			if (cmp(tab[j - 1], tab[j]) > 0)
				ft_swap_cp(&tab[j - 1], &tab[j]);
	}
}
