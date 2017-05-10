/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_labellst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:54:26 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/23 12:54:36 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

t_label	*new_labellst(const char *s, int intr_pre)
{
	t_label		*new;

	new = NULL;
	new = (t_label *)malloc(sizeof(t_label));
	new->name_label = ft_strdup(s);
	new->nb_pre = intr_pre;
	new->next = NULL;
	return (new);
}

void	add_to_labellst(t_label **lst, const char *s, int instr_pre)
{
	t_label	*tmp;

	tmp = *lst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_labellst(s, instr_pre);
	}
	else
		*lst = new_labellst(s, instr_pre);
}

t_label	*del_labellst(t_label *lst)
{
	t_label		*tmp;
	t_label		*tmp2;

	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			tmp2 = tmp->next;
			ft_memdel((void **)&tmp->name_label);
			ft_memdel((void **)&tmp);
			tmp = tmp2;
		}
		lst = NULL;
	}
	return (lst);
}
