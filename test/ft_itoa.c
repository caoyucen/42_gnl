/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:46:32 by ycao              #+#    #+#             */
/*   Updated: 2017/03/23 22:37:17 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_output(int n, int len, char *str)
{
	int i;

	if (n < 0)
	{
		n = 0 - n;
		str[0] = '-';
		len++;
	}
	len = len + ft_itoabase(n) - 1;
	str[len + 1] = '\0';
	i = 0;
	while (n >= 1)
	{
		str[len - i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	return (str);
}

static void	ft_cn(int n, char *str)
{
	if (n == -2147483648)
		ft_strcpy(str, "-2147483648\0");
	if (n == 0)
	{
		str[0] = 0 + '0';
		str[1] = '\0';
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	str = (char*)malloc(sizeof(char) * 13);
	if (!str)
		return (NULL);
	if (n == -2147483648 || n == 0)
	{
		ft_cn(n, str);
		return (str);
	}
	len = 0;
	ft_output(n, len, str);
	return (str);
}
