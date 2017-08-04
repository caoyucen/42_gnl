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

int			ft_atoi(const char *str)
{
	int					neg;
	int					i;
	unsigned long long	num;

	neg = 1;
	i = 0;
	num = 0;
	if (!*str)
		return (0);
	while (ft_isspace(*(char*)str))
		str++;
	if (*str == '-' || *str == '+')
	{
		neg = ft_strneg((char*)str);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
		i++;
	}
	if (num > 9223372036854775807 || i >= 19)
		return (neg == -1 ? 0 : -1);
	return (neg * (int)num);
}
