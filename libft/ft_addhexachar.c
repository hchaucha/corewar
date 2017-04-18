/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addhexachar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:47:21 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/27 15:47:23 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_addhexachar(char *str, int ishexa)
{
	int				length;
	char			*new;

	length = ft_strlen(str);
	if (!(length == 1 && str[0] == '0' && ishexa))
	{
		new = ft_strnew(length + 2);
		new = ft_strcat(new, "0X");
		new = ft_strcat(new, str);
		ft_strdel(&str);
	}
	else
		new = str;
	return (new);
}
