/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 21:32:28 by ycao              #+#    #+#             */
/*   Updated: 2017/03/23 23:10:20 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strneg(char *str)
{
	int	neg;

	neg = 1;
	if (str[0] == '-')
		neg = -1;
	return (neg);
}