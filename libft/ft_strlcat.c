/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:37:17 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/03 17:37:30 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t a;
	size_t b;
	size_t c;

	c = n;
	b = ft_strlen(src);
	a = ft_strlen(dst) + b;
	while (*dst && n)
	{
		n--;
		dst++;
	}
	if (n == 0)
		return (c + b);
	i = 0;
	while (src[i] && n-- > 1)
		*dst++ = src[i++];
	*dst = 0;
	return (a);
}
