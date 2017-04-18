/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:08:27 by hchaucha          #+#    #+#             */
/*   Updated: 2017/02/16 16:40:48 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrstr(const char *s1, const char *s2)
{
	char	*tmp;
	char	*tmp2;

	if (!s2[0])
		return ((char*)s1 + strlen(s1));
	tmp = NULL;
	tmp2 = NULL;
	while (1)
	{
		tmp2 = strstr(s1, s2);
		if (!tmp2)
			return (tmp);
		tmp = tmp2;
		s1 = tmp2 + 1;
	}
}
