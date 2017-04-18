/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:55:02 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/11 18:15:57 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dup;

	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(*dup) * (len + 1));
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
