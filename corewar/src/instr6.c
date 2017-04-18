/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 20:21:59 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 20:22:03 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		op_lfork(t_tool *t, t_process *p)
{
	t_instr		trash;

	trash.one = get_param(t, (p->pc + 1) % MEM_SIZE, 2);
	trash.tmp = trash.one;
	if (trash.one < 0)
	{
		trash.one = (4096 - (-trash.one % MEM_SIZE));
		t->process = add_new_process(t->process, (p->pc + trash.one)
			% MEM_SIZE, p);
		if (t->opt.verbose)
			ft_printf("P %4d | lfork %d (%d)\n", p->num_process, trash.tmp,
				p->pc + trash.tmp);
	}
	else
	{
		t->process = add_new_process(t->process, (p->pc + trash.one)
			% MEM_SIZE, p);
		if (t->opt.verbose)
			ft_printf("P %4d | lfork %d (%d)\n", p->num_process, trash.tmp,
				p->pc + trash.one);
	}
	return (3);
}

int		op_aff(t_tool *t, t_process *p)
{
	t_instr		trash;

	t->ret = descript_ocp(t, t->arena[(p->pc + 1) % MEM_SIZE].value, 1, 4);
	if (t->type_arg[1] != 1)
		return (t->ret + 2);
	trash.one = get_param(t, (p->pc + 2) % MEM_SIZE, 1);
	trash.error_reg = (trash.one < 1 || trash.one > REG_NUMBER) ? 1 : 0;
	if (trash.error_reg > 0)
		return (3);
	if (!t->opt.ncurse && !t->opt.cycle && (p->reg[trash.one - 1] % 256))
		ft_printf("Aff: %c\n", p->reg[trash.one - 1] % 256);
	return (3);
}
