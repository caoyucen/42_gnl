/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:22:24 by ycao              #+#    #+#             */
/*   Updated: 2017/03/23 23:02:36 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		n_word;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	n_word = ft_word(s, c);
	str = (char**)malloc(sizeof(char*) * (n_word + 1));
	if (!str)
		return (NULL);
	str[n_word] = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i++] != c)
		{
			str[j] = ft_strnew(ft_wlen(&s[i - 1], c) + 1);
			ft_strncpy(str[j], &s[i - 1], ft_wlen(&s[i - 1], c));
			i = i - 1 + ft_wlen(&s[i - 1], c);
			j++;
		}
	}
	return (str);
}
