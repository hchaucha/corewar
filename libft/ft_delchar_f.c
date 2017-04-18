/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delchar_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:17:00 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/27 16:17:02 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_delchar_f(char *src, char c, int occu)
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
	ft_strdel(&src);
	return (new);
}
