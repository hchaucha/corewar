/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:55:32 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/23 12:55:33 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int			search_octet_instr_bis(const char *s, char *(*ptr_fonction)
			(const char *, const char *, size_t), t_tool *tool, int i)
{
	char	*tmp;

	if (((tmp = (ptr_fonction)(s, "live", 4)) != NULL))
		return (1 + get_octet_instr(tool, i, 4));
	else if (((tmp = (ptr_fonction)(s, "ld", 2)) != NULL))
		return (2 + get_octet_instr(tool, i, 4));
	else if (((tmp = (ptr_fonction)(s, "st", 2)) != NULL))
		return (2 + get_octet_instr(tool, i, 0));
	else if (((tmp = (ptr_fonction)(s, "add", 3)) != NULL))
		return (2 + get_octet_instr(tool, i, 0));
	else if (((tmp = (ptr_fonction)(s, "sub", 3)) != NULL))
		return (2 + get_octet_instr(tool, i, 0));
	else if (((tmp = (ptr_fonction)(s, "and", 3)) != NULL))
		return (2 + get_octet_instr(tool, i, 4));
	else if (((tmp = (ptr_fonction)(s, "xor", 3)) != NULL))
		return (2 + get_octet_instr(tool, i, 4));
	else if (((tmp = (ptr_fonction)(s, "or", 2)) != NULL))
		return (2 + get_octet_instr(tool, i, 4));
	else
		return (0);
}

int			search_octet_instr(const char *s, char *(*ptr_fonction)
			(const char *, const char *, size_t), t_tool *tool, int i)
{
	char	*tmp;

	if (((tmp = (ptr_fonction)(s, "zjmp", 4)) != NULL))
		return (1 + get_octet_instr(tool, i, 2));
	else if (((tmp = (ptr_fonction)(s, "lldi", 4)) != NULL))
		return (2 + get_octet_instr(tool, i, 2));
	else if (((tmp = (ptr_fonction)(s, "sti", 3)) != NULL))
		return (2 + get_octet_instr(tool, i, 2));
	else if (((tmp = (ptr_fonction)(s, "lfork", 5)) != NULL))
		return (1 + get_octet_instr(tool, i, 2));
	else if (((tmp = (ptr_fonction)(s, "fork", 4)) != NULL))
		return (1 + get_octet_instr(tool, i, 2));
	else if (((tmp = (ptr_fonction)(s, "ldi", 3)) != NULL))
		return (2 + get_octet_instr(tool, i, 2));
	else if (((tmp = (ptr_fonction)(s, "lld", 3)) != NULL))
		return (2 + get_octet_instr(tool, i, 4));
	else if (((tmp = (ptr_fonction)(s, "aff", 3)) != NULL))
		return (2 + get_octet_instr(tool, i, 0));
	return (search_octet_instr_bis(s, *ptr_fonction, tool, i));
}

int			get_octet_instr(t_tool *tool, int i, int dir)
{
	int nb_octet;

	nb_octet = 0;
	nb_octet += tool->arg_ocp[i][0];
	nb_octet += tool->arg_ocp[i][1] * dir;
	nb_octet += tool->arg_ocp[i][2] * 2;
	return (nb_octet);
}

void		get_label_index(t_tool *tool)
{
	char	**instr;
	int		i;
	t_label	*tmp;

	instr = tool->instr;
	i = 0;
	tmp = NULL;
	if (tool->label)
		tmp = tool->label;
	while (instr[i])
	{
		while (tmp && i == tmp->nb_pre)
		{
			tmp->adresse_label = tool->nb_octet;
			tmp = tmp->next;
		}
		tool->nb_octet += search_octet_instr(instr[i], ft_strnstr, tool, i);
		i++;
	}
	while (tmp)
	{
		tmp->adresse_label = tool->nb_octet;
		tmp = tmp->next;
	}
}
