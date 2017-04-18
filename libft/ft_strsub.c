/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 13:00:09 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/11 18:18:00 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t n)
{
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = ft_strnew(n);
	if (tmp)
		ft_strncpy(tmp, str + start, n);
	return (tmp);
}
