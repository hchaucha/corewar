/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:16:12 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/27 16:16:14 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_delchar(char *src, char c, int occu)
{
	int		i;
	int		n;
	char	*new;

	i = 0;
	n = 0;
	new = ft_strnew(ft_strlen(src) - occu);
	while (src[i])
	{
		if (src[i] != c)
		{
			new[n] = src[i];
			n++;
		}
		i++;
	}
	return (new);
}
