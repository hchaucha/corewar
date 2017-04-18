/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:51:13 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/10 14:51:15 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void		algo(int ac, char **av, t_tool *tool)
{
	init_struct(tool);
	stock_file(ac, av, tool);
	get_nb_label_instr(tool);
	create_tab_instruction(tool);
	get_ocp_index(tool);
	get_label_index(tool);
	create_cor_file(tool, ac, av);
	free_things(tool);
}
