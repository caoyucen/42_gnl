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

static void	ft_reset_rest(char **rest, int i)
{

	/*mark   mark */
	ft_putendl("reset");
	/*mark   mark */
	int j;

	j = 0;
	while (*rest[++i])
	{
		*rest[j] = *rest[i];
		j++;
	}
	*rest[j] = '\0';
}

static int	read_the_buf(const int fd, char *buf, char **rest)
{
	int ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		*rest = ft_strjoin(*rest, buf);

		if (have_it(*rest))
		{
			/*mark   mark */
			// ft_putendl(*rest);
			// ft_putendl(" <- this is in buf");
			/*mark   mark */

			return (1);
		}
	}
	if (ret == 0)
		return (0);
	return (-1);
}

static int	get_the_rest(const int fd, char *buf, char **rest, char **line)
{
	int		i;

	/*mark   mark */
	ft_putendl("one");
	/*mark   mark */
	i = 0;
	if (!have_it(*rest))
	{
		/*mark   mark */
		ft_putendl("come to read");
		/*mark   mark */
		if (read_the_buf(fd, buf, rest) == 0) //调用, 且判断是否是eof
		{

			*line = ft_strnew(ft_strlen(*rest) + 1);
			ft_strcpy(*line, *rest);
			return (0);
		}
	}
	// /*mark   mark */
	// ft_putendl(*rest);
	// /*mark   mark */
	// /*mark   mark */
	// ft_putendl(" <- this should be rest");
	// /*mark   mark */
	*line = ft_strnew(ft_strlen(*rest) + 1);
	while (*rest[i])
	{
		if (*rest[i] == '\n')
		{
			ft_reset_rest(rest, i);
			return (1);
		}
		*line[i] = *rest[i];
		ft_putendl("I came here");
		ft_putendl(*rest);
		ft_putendl("^ this is rest");
		ft_putchar(*rest[0]);
		ft_putendl(" <- this is *rest[0]");
		ft_putchar(*rest[1]);
		ft_putendl(" <- this is *rest[1]");
		i++;
	}
	return (-1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*rest;
	char				*buf;

	buf = ft_strnew(BUFF_SIZE + 1);
	rest = ft_strnew(BUFF_SIZE + 1);
	//rest[0] = 'N';
	if (fd < 0 || !line || (read(fd, buf, 0) < 0))
		return (-1);
	while (get_the_rest(fd, buf, &rest, line))
	{
		/*mark   mark */
		ft_putendl("mark");
		/*mark   mark */
		return (1);
	}
	return (0);
}
