/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cor_instr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:56:57 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/23 12:56:59 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int			print_fd(t_tool *tool, int nb)
{
	ft_putchar_fd(nb, tool->fd);
	return (1);
}

void		print_instr(t_tool *tool, int i, int total_written)
{
	int		(*ptr_instr[16])(t_tool *tool, int instr, int total_written);

	ptr_instr[0] = live;
	ptr_instr[1] = ld;
	ptr_instr[2] = st;
	ptr_instr[3] = add;
	ptr_instr[4] = sub;
	ptr_instr[5] = i_and;
	ptr_instr[6] = i_or;
	ptr_instr[7] = i_xor;
	ptr_instr[8] = zjmp;
	ptr_instr[9] = ldi;
	ptr_instr[10] = sti;
	ptr_instr[11] = i_fork;
	ptr_instr[12] = lld;
	ptr_instr[13] = lldi;
	ptr_instr[14] = lfork;
	ptr_instr[15] = aff;
	while (tool->instr[i])
	{
		total_written += print_fd(tool, tool->op[i]);
		total_written += ptr_instr[tool->op[i] - 1](tool, i, total_written);
		i++;
	}
}
