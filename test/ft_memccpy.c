/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:13:44 by ycao              #+#    #+#             */
/*   Updated: 2017/03/23 19:46:49 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	*dest1;
	unsigned char	*src1;

	i = 0;
	c1 = (unsigned char)c;
	dest1 = (unsigned char*)dest;
	src1 = (unsigned char*)src;
	while (i < n)
	{
		dest1[i] = src1[i];
		if (src1[i] == c1)
		{
			return (dest1 + i + 1);
		}
		i++;
	}
	return (0);
}
