/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:07:22 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/03 18:08:32 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_atoi(const char *str)
{
	long long int	n;
	int				s;

	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if ((s = (*str == '-' ? -1 : 1)) == -1 || *str == '+')
		str++;
	while (ft_isdigit(*str))
		n = n * 10 + (*str++ - '0');
	return (s * n);
}
