/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:59:24 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/11 18:13:04 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n != 0)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		n--;
		if (*(unsigned char *)src == (unsigned char)c)
			return (++dst);
		dst++;
		src++;
	}
	return (NULL);
}
