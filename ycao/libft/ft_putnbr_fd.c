/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:26:47 by ycao              #+#    #+#             */
/*   Updated: 2017/03/23 18:10:28 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_positive_fd(int n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd((n + 48), fd);
		return ;
	}
	ft_put_positive_fd((n / 10), fd);
	ft_putchar_fd((n % 10 + 48), fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	ft_put_positive_fd(n, fd);
}
