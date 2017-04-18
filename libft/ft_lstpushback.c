/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 04:58:35 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/20 14:21:27 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstpushback(t_list **lst, void const *content, \
			size_t content_size)
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew((void *)content, content_size);
	}
	else
		*lst = ft_lstnew((void *)content, content_size);
}
