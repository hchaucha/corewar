/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:20:54 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/11 18:13:36 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *dst, const void *src, size_t n)
{
	while (n != 0)
	{
		if (*(unsigned char*)dst != *(unsigned char *)src)
			return (*(unsigned char *)dst - *(unsigned char *)src);
		dst++;
		src++;
		n--;
	}
	return (0);
}
