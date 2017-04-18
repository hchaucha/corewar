/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:34:40 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/06 18:06:55 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned int a;
	unsigned int b;

	if (!s1 || !s2)
		return (0);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (a == b)
	{
		a = 0;
		while (*s1 && *s2)
		{
			if (*s1 != *s2)
				a++;
			s1++;
			s2++;
		}
	}
	if (a != 0)
		return (0);
	else
		return (1);
}
