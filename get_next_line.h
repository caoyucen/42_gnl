/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 17:18:53 by ycao              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/07/12 18:55:00 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
=======
/*   Updated: 2017/06/26 17:18:56 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
>>>>>>> 295bb7033997b151ab1eed1513bdc24ea2fd0a2c
# include "libft/libft.h"

# define BUFF_SIZE 1000

<<<<<<< HEAD
=======
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

>>>>>>> 295bb7033997b151ab1eed1513bdc24ea2fd0a2c
int		get_next_line(const int fd, char **line);

#endif
