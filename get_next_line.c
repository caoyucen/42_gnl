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



int		get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		a;
	int		b;
	int		i;

	a = 0;
	b = 0;
	if (fd != 1 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		i = 0;
		while (i < ret)
		{
			if (buf[i] == '\n')
			{
				lina[a][b] = '\0';
				a++;
				b = 0;
				i++;
			}
			line[a][b] = buf[i];
			i++;
			b++;
		}
		line[a][b] = '\0';
		line[a] = NULL;
	}
	return (1);
}
