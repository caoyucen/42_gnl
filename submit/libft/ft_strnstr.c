/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:59:04 by ycao              #+#    #+#             */
/*   Updated: 2017/03/23 23:00:27 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*t;

	if (!*little)
		return ((char*)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		t = (char*)big + i;
		j = 0;
		while (little[j] && (i + j) < len)
		{
			if (big[i + j] != little[j])
			{
				t = NULL;
				break ;
			}
			j++;
		}
		if (t != NULL && little[j] == '\0')
			return (t);
		i++;
	}
	return (NULL);
}
