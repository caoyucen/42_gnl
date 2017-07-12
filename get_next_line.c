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

int		bufhasit(char *s)
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

int		get_the_rest(const int fd, char *rest, char **line)
{
	char *tem;
	int		i;
	int		j;

	if(!rest)
		rest = ft_strnew(1 + BUFF_SIZE)); //I have something here, can char* give to static char*?
	i = -1;
	j = -1;
	while (rest[++i])
	{
		line[++j] = rest[i];
		line[j] = '\0';
		if (rest[i] == '\n')
		{
			copy rest[i~] to tem;
			reset rest;
			copy tem to ret;
			return (0);
		}
	}
		reset rest;
		return (1);
}

int		get_the_buf(const int fd, char **line, char *a)
{
	int ret;

	while (ret = read(fd, buf, BUFF_SIZE))
	{
		if (buf has \n)
		{
			put into line;
			put into a;
			return (1);
		}
		else
			put into line;
	}
	if (ret == 0)
		return (0);
}

int		get_next_line(const int fd, char **line)
{
	static	char *rest = NULL; //to save the rest  norm???
	char	buf[BUFF_SIZE + 1];

	if (fd != 1 || !line || (read(fd, buf, 0) < 0)) //read(fd, buf, 0) read error or not, use 0 to give nothing push into buf
		return (-1);
	if (get_the_rest(fd, rest, line) == 0)
		return (1);
	if (get_the_buf(fd, line, rest->content) == 0)
		return (0);


	return (1);
}
