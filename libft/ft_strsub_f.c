/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 15:01:24 by atoupart          #+#    #+#             */
/*   Updated: 2016/04/16 15:01:30 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_f(char **str, unsigned int start, size_t n)
{
	char	*tmp;

	if (!*str)
		return (NULL);
	tmp = ft_strnew(n);
	if (tmp)
		ft_strncpy(tmp, *str + start, n);
	ft_strdel(str);
	return (tmp);
}
