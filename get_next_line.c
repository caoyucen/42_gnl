/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 17:18:38 by ycao              #+#    #+#             */
/*   Updated: 2017/06/26 17:18:42 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int		have_it(char *s)
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

void ft_reset_rest(char *rest, int i)
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

int		get_the_rest(const int fd, char *rest, char **line, int n)
{
	int		i;

	i = -1;
	n = 0;
	while (rest[++i])
	{
		if (rest[i] == '\n')
		{
			ft_reset_rest(rest, i);
			return (0);
		}
		line[n] = rest[i];
		line[n + 1] = '\0';
		n++;
	}
		ft_strclr(rest);
		return (1);
}

int		read_the_buf(const int fd, char **line, char *rest, int n)
{
	int ret;
	int i;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (have_it(buf))
		{
			i = -1;
			while (buf[++i])
			{
				if (buf[i] == '\n')
				{
					ft_strcpy(rest, (buf + i)); //remember this, this is very important
					return (1);
				}
				line[n + i] = buf[i];
			}
		}
		else
			ft_strcpy(rest, buf);
	}
	if (ret == 0)
		return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	rest[BUFF_SIZE + 1]; //to save the rest
	static int	n;
	char				*buf;

	buf = ft_strnew(BUFF_SIZE);
	n = 0;
	if (fd != 1 || !line || (read(fd, buf, 0) < 0)) //read(fd, buf, 0) read error or not, use 0 to give nothing push into buf
		return (-1);
	if (get_the_rest(fd, rest, line, n) == 0)
		return (1);
	if (read_the_buf(fd, line, rest, n) == 0)
		return (0);
	return (1);
}
