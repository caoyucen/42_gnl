/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:03:53 by ycao              #+#    #+#             */
/*   Updated: 2017/03/23 23:33:44 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && ft_isspace(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (ft_strnew(0));
	len = ft_strlen(s) - 1;
	while (ft_isspace(s[len]))
		len--;
	str = ft_strnew(len + 1 - i);
	if (!str)
		return (NULL);
	ft_strncpy(str, s + i, (len + 1 - i));
	return (str);
}
