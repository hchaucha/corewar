/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:02:37 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/11 18:17:11 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	i = 0;
	while (i < n && d[i] != '\0' & s[i] != '\0')
	{
		if (d[i] != s[i])
			return (d[i] - s[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (d[i] - s[i]);
}
