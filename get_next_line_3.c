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

// static int	have_it(char *s)
// {
// 	int		i;
//
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == '\n')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }
// ft_strchr(buff, '\n')
//ft_strchr(const char *s, int c)

static t_list	ft_create_list(int fd)
{
	t_list	*list;

}

static char *ft_get_tem(const int fd, t_list **rest_list, char *tem)
{
	if (!rest_list || !*rest_list)
		*rest_list =
	return (tem);
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

static int	read_the_buf(const int fd, char *rest, char **line, char *tem)
{
	int ret;
	char *buf;

	buf = ft_strnew(BUFF_SIZE + 1);
	if (ft_strchr(tem, '\n'))
	{
		ft_reset_rest(rest, line, tem);
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		tem = ft_strjoin(tem, buf);
		if (ft_strchr(tem, '\n'))
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
	if (ret < 0)
		return (-1);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static t_list	*rest_list;
	char					*tem;
	int						n;

	tem = ft_strnew(BUFF_SIZE + 1);
	if (fd < 0 || !line)
		return (-1);
	//inital tem;
	ft_get_tem(fd, &rest_list, tem);
	{
	//tem = ft_strcpy(tem, rest);
	n = read_the_buf(fd, buf, rest, line, tem);
	if (n == 0)
		return (0);
	else if (n == -1)
		return (-1);
	return (1);
}
