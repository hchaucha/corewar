/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 00:45:08 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/09 00:45:21 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_memdup(char *file, int i)
{
	char *tmp;

	tmp = ft_memalloc(i);
	ft_memcpy(tmp, file, i);
	return (tmp);
}
