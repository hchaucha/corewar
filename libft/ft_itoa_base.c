/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 18:28:46 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/10 18:28:50 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char	*ft_reverse(char *num, int neg)
{
	char	*number;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(num);
	if (!(number = (char *)malloc(sizeof(char) * (len + neg + 1))))
		return (NULL);
	if (neg == 1)
		number[i++] = '-';
	while (--len >= 0)
		number[i++] = num[len];
	number[i] = '\0';
	return (number);
}

char		*ft_itoa_base(long long int n, int base)
{
	int		i;
	int		neg;
	char	num[32];
	char	*ref;

	ref = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	neg = 0;
	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	i = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	while (n > 0)
	{
		num[i++] = ref[n % base];
		n /= base;
	}
	num[i] = '\0';
	return (ft_reverse(num, neg));
}
