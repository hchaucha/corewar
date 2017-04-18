/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:47:26 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/11 18:15:16 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nbr)
{
	int tmp;

	tmp = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
		{
			ft_putnbr(214748364);
			nbr = -8;
		}
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		tmp = nbr + '0';
		write(1, &tmp, 1);
	}
}
