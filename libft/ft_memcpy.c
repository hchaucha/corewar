/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:13:46 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/11 18:13:47 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*d;
	const char		*s;

	i = 0;
	d = dst;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
