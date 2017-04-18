/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strintercal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 13:21:42 by atoupart          #+#    #+#             */
/*   Updated: 2016/10/03 13:21:47 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strintercal(const char *s1, const char c, const char *s2)
{
	char		*out;
	char		*pt_out;
	size_t		len_out;

	len_out = ft_strlen(s1) + ft_strlen(s2) + 2;
	if ((out = ft_strnew(len_out)) == NULL)
		return (NULL);
	pt_out = out;
	while (*s1)
	{
		*pt_out = *s1;
		pt_out++;
		s1++;
	}
	*pt_out = c;
	pt_out++;
	while (*s2)
	{
		*pt_out = *s2;
		pt_out++;
		s2++;
	}
	*pt_out = '\0';
	return (out);
}
