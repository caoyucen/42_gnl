/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 23:07:09 by ycao              #+#    #+#             */
/*   Updated: 2017/03/15 20:46:40 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int l;
	int i;

	l = ft_min_strlen(s1, s2);
	i = 0;
	while (i < l)
	{
		if (s1[i] != s2[i])
			return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
		i++;
	}
	if (ft_strlen(s1) == ft_strlen(s2))
		return (0);
	else
		return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}
