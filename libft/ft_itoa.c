/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:16:40 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/11 18:12:26 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizeofsize(int n)
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

char		*ft_itoa(int n)
{
	char	*s;
	int		size;
	int		i;

	size = ft_sizeofsize(n);
	i = size;
	s = malloc((size + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (n > 9)
	{
		s[--size] = (n % 10) + 48;
		n = n / 10;
	}
	s[size - 1] = n + 48;
	s[i] = '\0';
	return (s);
}
