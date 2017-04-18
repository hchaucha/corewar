/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddnchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:47:07 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/27 15:47:09 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_straddnchar(char *str, int way, int n, char c)
{
	int			i;
	int			length;
	char		*new;

	length = ft_strlen(str);
	new = ft_strnew(length + n);
	i = 0;
	if (way)
	{
		new = ft_strcpy(new, str);
		while (i < n)
			new[length + i++] = c;
	}
	else
	{
		while (i < n)
			new[i++] = c;
		new = ft_strcat(new, str);
	}
	ft_strdel(&str);
	return (new);
}
