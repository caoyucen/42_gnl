/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 16:35:43 by ycao              #+#    #+#             */
/*   Updated: 2017/08/08 14:05:24 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*create_rest(int fd)
{
	t_list	*ret;
	t_rest	*new;

	new = (t_rest *)malloc(sizeof(t_rest));
	if (!new)
		return (NULL);
	new->str = ft_strnew(BUFF_SIZE);
	new->fd_number = fd;
	ret = ft_lstnew(new, sizeof(t_rest));
	free(new);
	return (ret);
}

static char		*ft_get_tem(int fd, t_list **rest_list)
{
	t_list *temp;

	if (!rest_list || !*rest_list)
		*rest_list = create_rest(fd);
	temp = *rest_list;
	while (temp)
	{
		if (((t_rest *)temp->content)->fd_number == fd)
			return (((t_rest *)temp->content)->str);
		temp = temp->next;
	}
	ft_lstadd(rest_list, create_rest(fd));
	return (((t_rest *)(*rest_list)->content)->str);
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

static int		read_the_buf(int fd, char *rest, char **line, char *tem)
{
	int		ret;
	char	*buf;
	char	*temfree;

	buf = ft_strnew(BUFF_SIZE + 1);
	if (ft_strchr(tem, '\n'))
	{
		ft_reset_rest(rest, line, tem);
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temfree = tem;
		tem = ft_strjoin(tem, buf);
		free(temfree);
		if (ft_strchr(tem, '\n'))
		{
			ft_reset_rest(rest, line, tem);
			return (1);
		}
	}
	ft_reset_rest(rest, line, tem);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*rest_list;
	char			*tem;
	char			*rest;
	int				n;

	tem = ft_strnew(BUFF_SIZE + 1);
	if (fd < 0 || !line || read(fd, tem, 0) < 0)
		return (-1);
	rest = ft_get_tem(fd, &rest_list);
	if (rest)
		tem = ft_strcpy(tem, rest);
	n = read_the_buf(fd, rest, line, tem);
	if (n == 0)
	{
		if (!(*line)[0])
			return (0);
	}
	else if (n == -1)
		return (-1);
	return (1);
}
