/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:13:16 by ycao              #+#    #+#             */
/*   Updated: 2017/03/23 22:42:36 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*destaddr;
	char	*srcaddr;

	destaddr = (char*)dest;
	srcaddr = (char*)src;
	while (n > 0)
	{
		*destaddr = *srcaddr;
		destaddr++;
		srcaddr++;
		n--;
	}
	return (dest);
}
