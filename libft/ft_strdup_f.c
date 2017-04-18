/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 11:55:26 by atoupart          #+#    #+#             */
/*   Updated: 2016/04/18 11:55:38 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup_f(char **s1)
{
	int		len;
	char	*dup;

	len = ft_strlen(*s1);
	dup = (char *)malloc(sizeof(*dup) * (len + 1));
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, *s1);
	ft_strdel(s1);
	return (dup);
}
