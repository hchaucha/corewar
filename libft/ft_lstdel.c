/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 17:20:17 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/14 14:53:11 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst || del)
	{
		while (*alst != NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = (*alst)->next;
		}
	}
}
