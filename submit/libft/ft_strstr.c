/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:44:27 by ycao              #+#    #+#             */
/*   Updated: 2017/03/23 21:56:22 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*t;

	i = 0;
	if (!*little)
		return ((char*)big);
	while (big[i])
	{
		if (big[i] == little[0])
		{
			t = (char*)big + i;
			j = 0;
			while (big[i + j] == little[j])
			{
				if (little[j + 1] == '\0')
					return (t);
				j++;
			}
			t = NULL;
		}
		i++;
	}
	return (NULL);
}
