/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:08:27 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:34:09 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_is_here(const char *s1, const char *s2)
{
	if (*s2 == '\0')
		return (1);
	if (*s1 == *s2)
		return (ft_str_is_here(s1 + 1, s2 + 1));
	return (0);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	if (ft_str_is_here(s1, s2))
		return ((char *)s1);
	if (*s1 == '\0')
		return (NULL);
	return (ft_strstr(s1 + 1, s2));
}
