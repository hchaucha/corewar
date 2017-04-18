/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 19:26:46 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/09 18:30:08 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		k;

	if (!s)
		return (0);
	if (*s == '\0')
		return ((char *)s);
	i = 0;
	k = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t' || s[k] == '\0')
		k--;
	return (ft_strsub(s, i, k - i + 1));
}
