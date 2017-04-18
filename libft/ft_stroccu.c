/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stroccu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:06:42 by hchaucha          #+#    #+#             */
/*   Updated: 2016/09/23 03:06:47 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stroccu(const char *str, char c)
{
	int	i;
	int nbr;

	i = -1;
	nbr = 0;
	if (str == NULL || c == '\0')
		return (0);
	while (str[++i] != '\0')
	{
		if (str[i] == c)
			nbr++;
	}
	return (nbr);
}
