/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:27:58 by nlagache          #+#    #+#             */
/*   Updated: 2017/03/27 15:12:01 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void		free_things_2(t_tool *tool)
{
	t_process	*tmp;
	t_process	*del;

	tmp = tool->process;
	while (tmp != NULL)
	{
		del = tmp;
		free(del->reg);
		tmp = tmp->next;
		free(del);
	}
	free(tmp);
	tool->process = NULL;
}

void		free_things(t_tool *tool)
{
	t_champ		*tmp;
	t_champ		*del;

	tmp = tool->champ;
	while (tmp != NULL)
	{
		del = tmp;
		free(del->name);
		free(del->comment);
		free(del->file);
		free(del);
		tmp = tmp->next;
	}
	if (tool->process)
		free_things_2(tool);
	tool->champ = NULL;
	free(tool->param);
	free(tool->type_arg);
	free(tool->arena);
}

void		free_trash(t_trash *trash)
{
	t_trash		*tmp;
	t_trash		*del;

	if (trash != NULL)
	{
		tmp = trash;
		del = tmp;
		free(del->name);
		free(del->comment);
		free(del->file);
	}
	trash = NULL;
}
