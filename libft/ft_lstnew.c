/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:07:24 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/14 18:22:10 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->next = NULL;
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	else
	{
		if (!(new->content = ft_memcpy(ft_memalloc(sizeof(content_size)), \
			(void*)content, content_size)))
			return (NULL);
		new->content_size = content_size;
	}
	return (new);
}
