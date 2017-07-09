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

int		get_the_rest(const int fd, static	t_list rest, char **line)
{
	char *tem;

	if (XXX(rest->content))
	if (!rest)
		ft_lstnew("\0", fd); //here fd is not the sizeof content, acltully is a mark for the file(fd)

}

int		get_the_buf(const int fd, char **line, char *tem)
{
	int ret;

	while (ret = read(fd, buf, BUFF_SIZE))
	{


	}

}

int		get_next_line(const int fd, char **line)
{
	static	t_list rest = NULL; //to save the rest  norm???
	char	buf[BUFF_SIZE + 1];


	if (fd != 1 || !line || (read(fd, buf, 0) < 0)) //read(fd, buf, 0) read error or not, use 0 to give nothing push into buf
		return (-1);


	return (1);
}
