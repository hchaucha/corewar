/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:56:10 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/23 12:56:11 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void		init_struct(t_tool *tool)
{
	tool->file = NULL;
	tool->nb_label = 0;
	tool->label = NULL;
	tool->nb_instr = 0;
	tool->instr = NULL;
	tool->arg_ocp = NULL;
	tool->ocp = NULL;
	tool->nb_octet = 0;
	tool->fd = 0;
	tool->spec = 0;
}
