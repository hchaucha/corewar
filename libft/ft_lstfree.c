/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:19:17 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/27 16:19:18 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list *lst)
{
	if (lst->next)
		ft_lstfree(lst->next);
	if (lst->content)
		free(lst->content);
	free(lst);
}
