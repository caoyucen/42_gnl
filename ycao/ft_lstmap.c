/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 10:28:42 by ycao              #+#    #+#             */
/*   Updated: 2017/01/20 13:11:51 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*ret;
	t_list	*new_head;

	temp = NULL;
	new_head = NULL;
	if (!lst || !f)
		return (NULL);
	ret = f(lst);
	new_head = ret;
	while (lst->next)
	{
		temp = f(lst->next);
		ret->next = temp;
		ret = ret->next;
		lst = lst->next;
	}
	return (new_head);
}
