/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 18:16:25 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/10 18:16:28 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uitoa_base(unsigned long long n, int base)
{
	int		tab[100];
	int		i;
	char	*str;
	int		j;

	j = 0;
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (n > 0)
	{
		tab[i++] = n % base;
		n = n / base;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	while (i--)
	{
		if (base > 10 && tab[i] > 9)
			str[j] = ((tab[i] + 87));
		else
			str[j] = (tab[i] + 48);
		j++;
	}
	str[j] = '\0';
	return (str);
}
