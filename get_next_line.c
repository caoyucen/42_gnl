/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 17:18:38 by ycao              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/07/12 19:00:11 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	have_it(char *s)
=======
/*   Updated: 2017/06/26 17:18:42 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int		have_it(char *s)
>>>>>>> 295bb7033997b151ab1eed1513bdc24ea2fd0a2c
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

<<<<<<< HEAD
static void	ft_reset_rest(char *rest, int i)
=======
void ft_reset_rest(char *rest, int i)
>>>>>>> 295bb7033997b151ab1eed1513bdc24ea2fd0a2c
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

<<<<<<< HEAD
static int	get_the_rest(char *rest, char **line, int n)
=======
int		get_the_rest(const int fd, char *rest, char **line, int n)
>>>>>>> 295bb7033997b151ab1eed1513bdc24ea2fd0a2c
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
<<<<<<< HEAD
		*line[n] = rest[i];
		*line[n + 1] = '\0';
		n++;
	}
	ft_strclr(rest);
	return (1);
}

static int	read_the_buf(const int fd, char *buf, char **line, char *rest, int n)
=======
		line[n] = rest[i];
		line[n + 1] = '\0';
		n++;
	}
		ft_strclr(rest);
		return (1);
}

int		read_the_buf(const int fd, char **line, char *rest, int n)
>>>>>>> 295bb7033997b151ab1eed1513bdc24ea2fd0a2c
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
<<<<<<< HEAD
				*line[n + i] = buf[i];
=======
				line[n + i] = buf[i];
>>>>>>> 295bb7033997b151ab1eed1513bdc24ea2fd0a2c
			}
		}
		else
			ft_strcpy(rest, buf);
	}
	if (ret == 0)
		return (0);
<<<<<<< HEAD
	return (-1);
}

int	get_next_line(const int fd, char **line)
{
	static char	rest[BUFF_SIZE + 1]; //to save the rest
	static int	n;
	char		*buf;
=======
}

int		get_next_line(const int fd, char **line)
{
	static char	rest[BUFF_SIZE + 1]; //to save the rest
	static int	n;
	char				*buf;
>>>>>>> 295bb7033997b151ab1eed1513bdc24ea2fd0a2c

	buf = ft_strnew(BUFF_SIZE);
	n = 0;
	if (fd != 1 || !line || (read(fd, buf, 0) < 0)) //read(fd, buf, 0) read error or not, use 0 to give nothing push into buf
		return (-1);
<<<<<<< HEAD
	if (get_the_rest(rest, line, n) == 0)
		return (1);
	if (read_the_buf(fd, buf, line, rest, n) == 0)
=======
	if (get_the_rest(fd, rest, line, n) == 0)
		return (1);
	if (read_the_buf(fd, line, rest, n) == 0)
>>>>>>> 295bb7033997b151ab1eed1513bdc24ea2fd0a2c
		return (0);
	return (1);
}
