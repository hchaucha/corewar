/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 11:53:11 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/13 11:53:14 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void		free_things(t_tool *tool)
{
	int y;

	y = -1;
	while (tool->file[++y] != NULL)
		free(tool->file[y]);
	free(tool->file);
	tool->file = NULL;
	y = -1;
	while (tool->instr[++y] != NULL)
		free(tool->instr[y]);
	free(tool->instr);
	tool->instr = NULL;
	free(tool->ocp);
	y = -1;
	while (++y < tool->nb_instr)
		free(tool->arg_ocp[y]);
	free(tool->arg_ocp);
	tool->arg_ocp = NULL;
	free(tool->op);
	tool->label = del_labellst(tool->label);
}
