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

static int		ft_reset_rest(char *rest, char **line, char *tem)
{
	int i;
	int j;
	int z;

	i = -1;
	j = -1;
	while (rest[++i])
		rest[i] = '\0';
	*line = ft_strnew(ft_strlen(tem) + 1);
	while (tem[++j])
	{
		if (tem[j] == '\n')
		{
			z = -1;
			while (tem[++j])
				rest[++z] = tem[j];
			return (1);
		}
		(*line)[j] = tem[j];
	}
	return (0);
}

static int	read_the_buf(const int fd, char *rest, char **line, char *tem, char *buf)
{
	int ret;
	//char buf[BUFF_SIZE + 1];

	if (have_it(tem))
	{
		ft_reset_rest(rest, line, tem);
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		tem = ft_strjoin(tem, buf);
		if (have_it(tem))
		{
			ft_reset_rest(rest, line, tem);
			return (1);
		}
	}
	ft_reset_rest(rest, line, tem);
	if (ret == 0)
	{
		if (!(*line)[0])
			return (0);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	rest[BUFF_SIZE + 1];
	char				*buf;
	char				*tem;

	buf = ft_strnew(BUFF_SIZE + 1);
	tem = ft_strnew(BUFF_SIZE + 1);
	if (fd < 0 || !line || (read(fd, buf, 0) < 0))
		return (-1);
	tem = ft_strcpy(tem, rest);
	if (read_the_buf(fd, rest, line, tem, buf) == 0)
		return (0);
	return (1);
}
