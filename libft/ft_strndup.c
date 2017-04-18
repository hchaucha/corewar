/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:05:45 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/21 20:06:05 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n)
	{
		new[i] = str[i];
		i++;
	}
	new[n] = 0;
	return (new);
}
