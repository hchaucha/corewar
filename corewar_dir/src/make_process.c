/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:19:29 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 12:19:33 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void		give_cycle_to_wait(t_process *tmp, int value_op)
{
	tmp->value_op = value_op;
	if (value_op == 1 || value_op == 4 || value_op == 5 || value_op == 13)
		tmp->cycle_to_wait = 9;
	else if (value_op == 2 || value_op == 3)
		tmp->cycle_to_wait = 4;
	else if (value_op == 6 || value_op == 7 || value_op == 8)
		tmp->cycle_to_wait = 5;
	else if (value_op == 9)
		tmp->cycle_to_wait = 19;
	else if (value_op == 10 || value_op == 11)
		tmp->cycle_to_wait = 24;
	else if (value_op == 12)
		tmp->cycle_to_wait = 799;
	else if (value_op == 14)
		tmp->cycle_to_wait = 49;
	else if (value_op == 15)
		tmp->cycle_to_wait = 999;
	else if (value_op == 16)
		tmp->cycle_to_wait = 1;
}

int			make_instr(t_tool *t, t_process *tmp, int total_live)
{
	int ret;

	t->arena[tmp->pc].here_process = 0;
	ret = g_opfunc[tmp->value_op - 1].func(t, tmp);
	if (t->opt.jump && (tmp->value_op != 9 || (tmp->value_op == 9 && ret == 3)))
	{
		ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", ret, tmp->pc, tmp->pc + ret);
		t->i = -1;
		while (++t->i < ret)
			ft_printf("%0.2x ", t->arena[(tmp->pc + t->i) % MEM_SIZE].value);
		ft_printf("\n");
	}
	tmp->pc = (tmp->pc + ret) % MEM_SIZE;
	t->arena[tmp->pc].here_process = 1;
	if (tmp->live && (total_live += tmp->live))
		tmp->cycle_no_live = 0;
	tmp->live = 0;
	return (total_live);
}

int			make_process(t_tool *tool)
{
	int			total_live;
	int			value_op;
	t_process	*tmp;

	tmp = tool->process;
	total_live = 0;
	while (tmp)
	{
		value_op = tool->arena[tmp->pc].value;
		tmp->cycle_no_live++;
		if (tmp->cycle_to_wait == 0 && value_op >= 1 && value_op <= 16)
			give_cycle_to_wait(tmp, value_op);
		else if (tmp->cycle_to_wait == 0 && (value_op == 0 || value_op > 16))
		{
			tool->arena[tmp->pc].here_process = 0;
			tmp->pc = (tmp->pc + 1) % MEM_SIZE;
			tool->arena[tmp->pc].here_process = 1;
		}
		else if ((--tmp->cycle_to_wait) == 0)
			total_live = make_instr(tool, tmp, total_live);
		tmp = tmp->next;
	}
	return (total_live);
}
