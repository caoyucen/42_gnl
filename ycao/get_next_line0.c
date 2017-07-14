/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 17:18:38 by ycao              #+#    #+#             */
/*   Updated: 2017/07/12 19:00:11 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	have_it(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	ft_reset_rest(char *rest, int i)
{
	int j;

	j = 0;
	while (rest[++i])
	{
		rest[j] = rest[i];
		j++;
	}
	rest[j] = '\0';
}

static int	get_the_rest(const int fd, char *rest, char **line, int n, char *buf)
{
	int		i;
	int ret;

	i = -1;
	if (have_it(rest) or end)
	{
		*line = ft_strnew(ft_strlen(rest) + 1);
		while (rest[++i])
		{
			if (rest[i] == '\n' or end)
			{
				n = n + i;
				ft_reset_rest(rest, i);
				return (1);
			}
			*line[i] = rest[i]; //something wrong here
			ft_putchar(*line[i]);
		}
	}
	return (0);
}

static int	read_the_buf(const int fd, char **line, char *rest, int n)
{
	if (get_the_rest == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == 0)
			return (0);
		rest = ft_strjoin(rest, buf);
		if (get_the_rest == 1)
		{
			return (1);
		}


	}
}


int	get_next_line(const int fd, char **line)
{
	static char	rest[BUFF_SIZE + 1];
	int					n;
	char				*buf;
	int					tem;

	buf = ft_strnew(BUFF_SIZE);
	n = 0;
	tem = 0;



	if (fd < 0 || !line || (read(fd, buf, 0) < 0))
		return (-1);
	while ((tem = get_the_rest(fd, rest, line, n, buf)) > 0)
	{
		if (tem == 1)
			return (1);
		if (tem == 2)
			return (0);
	}

	// if (read_the_buf(fd, line, rest, n, buf) == 0)
	// 	return (0);
	// ft_putstr("come here\n");
	return (1);
}
