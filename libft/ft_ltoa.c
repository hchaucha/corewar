/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 01:10:28 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/30 01:10:29 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_norm(long long n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		i = 2;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_ltoa(long long n)
{
	char	*s;
	int		size;
	int		i;

	size = ft_norm(n);
	i = size;
	s = malloc((size + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (n > 9)
	{
		s[--size] = (n % 10) + '0';
		n = n / 10;
	}
	s[size - 1] = n + '0';
	s[i] = '\0';
	return (s);
}
