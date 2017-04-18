/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 14:46:31 by atoupart          #+#    #+#             */
/*   Updated: 2016/04/16 14:46:38 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_f(char **s1, char *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc((ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	res = ft_strcpy(res, *s1);
	res = ft_strcat(res, s2);
	ft_strdel(s1);
	return (res);
}
