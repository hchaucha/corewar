/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:25:35 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 13:25:36 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

t_champ			*new_champlst(t_trash *trash)
{
	t_champ		*new;

	new = NULL;
	new = (t_champ *)malloc(sizeof(t_champ));
	new->name = ft_strdup(trash->name);
	new->comment = ft_strdup(trash->comment);
	new->id_champ = trash->id_champ;
	new->file = ft_memdup(trash->file, trash->nb_octet);
	new->nb_octet = trash->nb_octet;
	new->next = NULL;
	free_trash(trash);
	return (new);
}

void			add_to_champlst(t_champ **lst, t_trash *trash)
{
	t_champ	*tmp;

	tmp = *lst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_champlst(trash);
	}
	else
		*lst = new_champlst(trash);
}
