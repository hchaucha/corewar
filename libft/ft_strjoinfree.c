/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 01:04:49 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/30 01:04:53 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2, int i)
{
	char	*fre;
	char	*fre1;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return ((char*)s2);
	else if (s2 == NULL)
		return ((char*)s1);
	fre = (char*)s1;
	fre1 = (char*)s2;
	str = ft_strjoin(s1, s2);
	if (i == 1 || i == 3)
		free(fre);
	if (i == 2 || i == 3)
		free(fre1);
	return (str);
}
